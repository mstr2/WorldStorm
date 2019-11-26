/*
 * Copyright (c) 2017 United States Government as represented by the Administrator of the
 * National Aeronautics and Space Administration. All Rights Reserved.
 */

package gov.nasa.worldwind.render;

import gov.nasa.worldwind.draw.DrawContext;
import gov.nasa.worldwind.geom.Matrix4;
import gov.nasa.worldwind.platform.GLES20;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.util.Logger;

import java.util.ResourceBundle;

public class SightlineProgram extends ShaderProgram {

    public static final Object KEY = SightlineProgram.class;

    protected int mvpMatrixId;

    protected int slpMatrixId;

    protected int rangeId;

    protected int depthSamplerId;

    protected int colorId;

    private float[] array = new float[32];

    public SightlineProgram(ResourceBundle resources) {
        try {
            String vs = resources.getString("raw.gov_nasa_worldwind_sightlineprogram_vert");
            String fs = resources.getString("raw.gov_nasa_worldwind_sightlineprogram_frag");
            this.setProgramSources(vs, fs);
            this.setAttribBindings("vertexPoint");
        } catch (Exception logged) {
            Logger.logMessage(Logger.ERROR, "SightlineProgram", "constructor", "errorReadingProgramSource", logged);
        }
    }

    protected void initProgram(DrawContext dc) {
        GLES20 gl = Platform.getGL();
        this.mvpMatrixId = gl.glGetUniformLocation(this.programId, "mvpMatrix");
        gl.glUniformMatrix4fv(this.mvpMatrixId, 1, false, this.array, 0);

        this.slpMatrixId = gl.glGetUniformLocation(this.programId, "slpMatrix");
        gl.glUniformMatrix4fv(this.slpMatrixId, 2, false, this.array, 0);

        this.rangeId = gl.glGetUniformLocation(this.programId, "range");
        gl.glUniform1f(this.rangeId, 0);

        this.colorId = gl.glGetUniformLocation(this.programId, "color");
        gl.glUniform4f(this.colorId, 1, 1, 1, 1);

        this.depthSamplerId = gl.glGetUniformLocation(this.programId, "depthSampler");
        gl.glUniform1i(this.depthSamplerId, 0); // GL_TEXTURE0
    }

    public void loadModelviewProjection(Matrix4 matrix) {
        matrix.transposeToArray(this.array, 0);
        Platform.getGL().glUniformMatrix4fv(this.mvpMatrixId, 1, false, this.array, 0);
    }

    public void loadSightlineProjection(Matrix4 projection, Matrix4 sightline) {
        projection.transposeToArray(this.array, 0);
        sightline.transposeToArray(this.array, 16);
        Platform.getGL().glUniformMatrix4fv(this.slpMatrixId, 2, false, this.array, 0);
    }

    public void loadRange(float range) {
        Platform.getGL().glUniform1f(this.rangeId, range);
    }

    public void loadColor(Color visibleColor, Color occludedColor) {
        visibleColor.premultiplyToArray(this.array, 0);
        occludedColor.premultiplyToArray(this.array, 4);
        Platform.getGL().glUniform4fv(this.colorId, 2, this.array, 0);
    }
}
