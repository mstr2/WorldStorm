/*
 * Copyright (c) 2016 United States Government as represented by the Administrator of the
 * National Aeronautics and Space Administration. All Rights Reserved.
 */

package gov.nasa.worldwind.render;

import gov.nasa.worldwind.draw.DrawContext;
import gov.nasa.worldwind.geom.Matrix3;
import gov.nasa.worldwind.geom.Matrix4;
import gov.nasa.worldwind.platform.GLES20;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.util.Logger;

import java.util.ResourceBundle;

public class BasicShaderProgram extends ShaderProgram {

    public static final Object KEY = BasicShaderProgram.class;

    protected boolean enablePickMode;

    protected boolean enableTexture;

    protected Matrix4 mvpMatrix = new Matrix4();

    protected Matrix3 texCoordMatrix = new Matrix3();

    protected Color color = new Color();

    protected int enablePickModeId;

    protected int enableTextureId;

    protected int mvpMatrixId;

    protected int texCoordMatrixId;

    protected int texSamplerId;

    protected int colorId;

    private float[] array = new float[16];

    public BasicShaderProgram(ResourceBundle resources) {
        try {
            String vs = resources.getString("raw.gov_nasa_worldwind_basicprogram_vert");
            String fs = resources.getString("raw.gov_nasa_worldwind_basicprogram_frag");
            this.setProgramSources(vs, fs);
            this.setAttribBindings("vertexPoint", "vertexTexCoord");
        } catch (Exception logged) {
            Logger.logMessage(Logger.ERROR, "BasicShaderProgram", "constructor", "errorReadingProgramSource", logged);
        }
    }

    protected void initProgram(DrawContext dc) {
        GLES20 gl = Platform.getGL();

        this.enablePickModeId = gl.glGetUniformLocation(this.programId, "enablePickMode");
        gl.glUniform1i(this.enablePickModeId, this.enablePickMode ? 1 : 0);

        this.enableTextureId = gl.glGetUniformLocation(this.programId, "enableTexture");
        gl.glUniform1i(this.enableTextureId, this.enableTexture ? 1 : 0);

        this.mvpMatrixId = gl.glGetUniformLocation(this.programId, "mvpMatrix");
        this.mvpMatrix.transposeToArray(this.array, 0); // 4 x 4 identity matrix
        gl.glUniformMatrix4fv(this.mvpMatrixId, 1, false, this.array, 0);

        this.texCoordMatrixId = gl.glGetUniformLocation(this.programId, "texCoordMatrix");
        this.texCoordMatrix.transposeToArray(this.array, 0); // 3 x 3 identity matrix
        gl.glUniformMatrix3fv(this.texCoordMatrixId, 1, false, this.array, 0);

        this.colorId = gl.glGetUniformLocation(this.programId, "color");
        float alpha = this.color.alpha;
        gl.glUniform4f(this.colorId, this.color.red * alpha, this.color.green * alpha, this.color.blue * alpha, alpha);

        this.texSamplerId = gl.glGetUniformLocation(this.programId, "texSampler");
        gl.glUniform1i(this.texSamplerId, 0); // GL_TEXTURE0
    }

    public void enablePickMode(boolean enable) {
        if (this.enablePickMode != enable) {
            this.enablePickMode = enable;
            Platform.getGL().glUniform1i(this.enablePickModeId, enable ? 1 : 0);
        }
    }

    public void enableTexture(boolean enable) {
        if (this.enableTexture != enable) {
            this.enableTexture = enable;
            Platform.getGL().glUniform1i(this.enableTextureId, enable ? 1 : 0);
        }
    }

    public void loadModelviewProjection(Matrix4 matrix) {
        // Don't bother testing whether mvpMatrix has changed, the common case is to load a different matrix.
        matrix.transposeToArray(this.array, 0);
        Platform.getGL().glUniformMatrix4fv(this.mvpMatrixId, 1, false, this.array, 0);
    }

    public void loadTexCoordMatrix(Matrix3 matrix) {
        if (!this.texCoordMatrix.equals(matrix)) {
            this.texCoordMatrix.set(matrix);
            matrix.transposeToArray(this.array, 0);
            Platform.getGL().glUniformMatrix3fv(this.texCoordMatrixId, 1, false, this.array, 0);
        }
    }

    public void loadColor(Color color) {
        if (!this.color.equals(color)) {
            this.color.set(color);
            float alpha = color.alpha;
            Platform.getGL().glUniform4f(this.colorId, color.red * alpha, color.green * alpha, color.blue * alpha, alpha);
        }
    }
}
