/*
 * Copyright (c) 2016 United States Government as represented by the Administrator of the
 * National Aeronautics and Space Administration. All Rights Reserved.
 */

package gov.nasa.worldwind.render;

import gov.nasa.worldwind.draw.DrawContext;
import gov.nasa.worldwind.platform.GLES20;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.util.Logger;

/**
 * Represents an OpenGL shading language (GLSL) shader program and provides methods for identifying and accessing shader
 * variables. Shader programs are configured by calling <code>setProgramSources</code> to specify the the GLSL vertex
 * shader and fragment shader source code, then made current by calling <code>useProgram</code>.
 */
public class ShaderProgram implements RenderResource {

    protected static final int VERTEX_SHADER = 0;

    protected static final int FRAGMENT_SHADER = 1;

    protected String[] programSources;

    protected String[] attribBindings;

    /**
     * Indicates the approximate size of the OpenGL resources referenced by this GPU program.
     */
    protected int programLength;

    /**
     * Indicates the OpenGL program object associated with this GPU program.
     */
    protected int programId;

    protected int[] shaderId = new int[2];

    protected boolean mustBuildProgram = true;

    public ShaderProgram() {
    }

    public String[] getProgramSources() {
        return programSources;
    }

    public void setProgramSources(String... programSources) {
        this.programSources = programSources;
        this.programLength = 0;
        this.mustBuildProgram = true;

        if (programSources != null) {
            for (String str : programSources) {
                this.programLength += (str != null) ? str.length() : 0;
            }
        }
    }

    public String[] getAttribBindings() {
        return attribBindings;
    }

    public void setAttribBindings(String... attribBindings) {
        this.attribBindings = attribBindings;
        this.mustBuildProgram = true;
    }

    public int getProgramLength() {
        return this.programLength;
    }

    @Override
    public void release(DrawContext dc) {
        this.deleteProgram(dc);
    }

    public boolean useProgram(DrawContext dc) {
        if (this.mustBuildProgram) {
            // Clear the program's build dirty bit.
            this.mustBuildProgram = false;

            // Remove any existing GLSL program.
            if (this.programId != 0) {
                this.deleteProgram(dc);
            }

            // Compile and link the GLSL program sources.
            if (this.programSources != null) {
                this.buildProgram(dc, this.programSources, this.attribBindings);
            }

            // Give subclasses an opportunity to initialize default GLSL uniform values.
            if (this.programId != 0) {
                int currentProgram = dc.currentProgram();
                try {
                    dc.useProgram(this.programId);
                    this.initProgram(dc);
                } finally {
                    dc.useProgram(currentProgram);
                }
            }
        }

        if (this.programId != 0) {
            dc.useProgram(this.programId);
        }

        return this.programId != 0;
    }

    protected void buildProgram(DrawContext dc, String[] programSource, String[] attribBindings) {
        int[] status = new int[1];
        GLES20 gl = Platform.getGL();

        int vs = gl.glCreateShader(GLES20.GL_VERTEX_SHADER);
        gl.glShaderSource(vs, programSource[VERTEX_SHADER]);
        gl.glCompileShader(vs);
        gl.glGetShaderiv(vs, GLES20.GL_COMPILE_STATUS, status, 0);

        if (status[0] != gl.GL_TRUE) {
            String msg = gl.glGetShaderInfoLog(vs);
            gl.glDeleteShader(vs);
            Logger.logMessage(Logger.ERROR, this.getClass().getSimpleName(), "buildProgram",
                "Error compiling GL vertex shader \n" + msg);
            return;
        }

        int fs = gl.glCreateShader(GLES20.GL_FRAGMENT_SHADER);
        gl.glShaderSource(fs, programSource[FRAGMENT_SHADER]);
        gl.glCompileShader(fs);
        gl.glGetShaderiv(vs, GLES20.GL_COMPILE_STATUS, status, 0);

        if (status[0] != GLES20.GL_TRUE) {
            String msg = gl.glGetShaderInfoLog(fs);
            gl.glDeleteShader(vs);
            gl.glDeleteShader(fs);
            Logger.logMessage(Logger.ERROR, this.getClass().getSimpleName(), "buildProgram",
                "Error compiling GL fragment shader \n" + msg);
            return;
        }

        int program = gl.glCreateProgram();
        gl.glAttachShader(program, vs);
        gl.glAttachShader(program, fs);

        if (attribBindings != null) {
            for (int i = 0; i < attribBindings.length; i++) {
                gl.glBindAttribLocation(program, i, attribBindings[i]);
            }
        }

        gl.glLinkProgram(program);
        gl.glGetProgramiv(program, GLES20.GL_LINK_STATUS, status, 0);

        if (status[0] != GLES20.GL_TRUE) {
            String msg = gl.glGetProgramInfoLog(program);
            gl.glDeleteProgram(program);
            gl.glDeleteShader(vs);
            gl.glDeleteShader(fs);
            Logger.logMessage(Logger.ERROR, this.getClass().getSimpleName(), "buildProgram",
                "Error linking GL program \n" + msg);
            return;
        }

        this.programId = program;
        this.shaderId[0] = vs;
        this.shaderId[1] = fs;
    }

    protected void initProgram(DrawContext dc) {

    }

    protected void deleteProgram(DrawContext dc) {
        if (this.programId != 0) {
            GLES20 gl = Platform.getGL();
            gl.glDeleteProgram(this.programId);
            gl.glDeleteShader(this.shaderId[VERTEX_SHADER]);
            gl.glDeleteShader(this.shaderId[FRAGMENT_SHADER]);
            this.programId = 0;
            this.shaderId[VERTEX_SHADER] = 0;
            this.shaderId[FRAGMENT_SHADER] = 0;
        }
    }
}
