/*
 * Copyright (c) 2016 United States Government as represented by the Administrator of the
 * National Aeronautics and Space Administration. All Rights Reserved.
 */

package gov.nasa.worldwind.render;

import gov.nasa.worldwind.draw.DrawContext;
import gov.nasa.worldwind.platform.GL;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.util.SparseArray;

public class Framebuffer implements RenderResource {

    protected static final int[] UNINITIALIZED_NAME = new int[1];

    protected int[] framebufferName = UNINITIALIZED_NAME;

    protected SparseArray<Texture> attachedTextures = new SparseArray<>();

    public Framebuffer() {
    }

    @Override
    public void release(DrawContext dc) {
        if (this.framebufferName[0] != 0) {
            this.deleteFramebuffer(dc);
            this.attachedTextures.clear();
        }
    }

    public boolean bindFramebuffer(DrawContext dc) {
        if (this.framebufferName == UNINITIALIZED_NAME) {
            this.createFramebuffer(dc);
        }

        if (this.framebufferName[0] != 0) {
            dc.bindFramebuffer(this.framebufferName[0]);
        }

        return this.framebufferName[0] != 0;
    }

    public boolean attachTexture(DrawContext dc, Texture texture, int attachment) {
        if (this.framebufferName == UNINITIALIZED_NAME) {
            this.createFramebuffer(dc);
        }

        if (this.framebufferName[0] != 0) {
            this.framebufferTexture(dc, texture, attachment);
            this.attachedTextures.put(attachment, texture);
        }

        return this.framebufferName[0] != 0;
    }

    public Texture getAttachedTexture(int attachment) {
        return this.attachedTextures.get(attachment);
    }

    public boolean isFramebufferComplete(DrawContext dc) {
        // Get the OpenGL framebuffer object status code.
        int e = this.framebufferStatus(dc);
        return e == GL.GL_FRAMEBUFFER_COMPLETE;
    }

    protected void createFramebuffer(DrawContext dc) {
        GL gl = Platform.getGL();
        int currentFramebuffer = dc.currentFramebuffer();
        try {
            this.framebufferName = new int[1];
            // Create the OpenGL framebuffer object.
            gl.glGenFramebuffers(1, this.framebufferName, 0);
            gl.glBindFramebuffer(GL.GL_FRAMEBUFFER, this.framebufferName[0]);
        } finally {
            // Restore the current OpenGL framebuffer object binding.
            gl.glBindFramebuffer(GL.GL_FRAMEBUFFER, currentFramebuffer);
        }
    }

    protected void deleteFramebuffer(DrawContext dc) {
        Platform.getGL().glDeleteFramebuffers(1, this.framebufferName, 0);
        this.framebufferName[0] = 0;
    }

    protected void framebufferTexture(DrawContext dc, Texture texture, int attachment) {
        int currentFramebuffer = dc.currentFramebuffer();
        try {
            // Make the OpenGL framebuffer object the currently active framebuffer.
            dc.bindFramebuffer(this.framebufferName[0]);
            // Attach the texture to the framebuffer object, or remove the attachment if the texture is null.
            int textureName = (texture != null) ? texture.getTextureName(dc) : 0;
            Platform.getGL().glFramebufferTexture2D(GL.GL_FRAMEBUFFER, attachment, GL.GL_TEXTURE_2D, textureName, 0 /*level*/);
        } finally {
            // Restore the current OpenGL framebuffer object binding.
            dc.bindFramebuffer(currentFramebuffer);
        }
    }

    protected int framebufferStatus(DrawContext dc) {
        int currentFramebuffer = dc.currentFramebuffer();
        try {
            // Make the OpenGL framebuffer object the currently active framebuffer.
            dc.bindFramebuffer(this.framebufferName[0]);
            // Get the OpenGL framebuffer object status code.
            return Platform.getGL().glCheckFramebufferStatus(GL.GL_FRAMEBUFFER);
        } finally {
            // Restore the current OpenGL framebuffer object binding.
            dc.bindFramebuffer(currentFramebuffer);
        }
    }
}
