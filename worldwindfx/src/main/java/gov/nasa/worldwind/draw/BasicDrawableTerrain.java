/*
 * Copyright (c) 2016 United States Government as represented by the Administrator of the
 * National Aeronautics and Space Administration. All Rights Reserved.
 */

package gov.nasa.worldwind.draw;

import gov.nasa.worldwind.geom.Range;
import gov.nasa.worldwind.geom.Sector;
import gov.nasa.worldwind.geom.Vec3;
import gov.nasa.worldwind.platform.GL;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.render.BufferObject;
import gov.nasa.worldwind.util.Pool;

public class BasicDrawableTerrain implements DrawableTerrain {

    public Sector sector = new Sector();

    public Vec3 vertexOrigin = new Vec3();

    public Range lineElementRange = new Range();

    public Range triStripElementRange = new Range();

    public BufferObject vertexPoints;

    public BufferObject vertexTexCoords;

    public BufferObject elements;

    private Pool<BasicDrawableTerrain> pool;

    protected BasicDrawableTerrain() {
    }

    public static BasicDrawableTerrain obtain(Pool<BasicDrawableTerrain> pool) {
        BasicDrawableTerrain instance = pool.acquire(); // get an instance from the pool
        return (instance != null) ? instance.setPool(pool) : new BasicDrawableTerrain().setPool(pool);
    }

    private BasicDrawableTerrain setPool(Pool<BasicDrawableTerrain> pool) {
        this.pool = pool;
        return this;
    }

    @Override
    public void recycle() {
        this.vertexPoints = null;
        this.vertexTexCoords = null;
        this.elements = null;

        if (this.pool != null) { // return this instance to the pool
            this.pool.release(this);
            this.pool = null;
        }
    }

    @Override
    public Sector getSector() {
        return this.sector;
    }

    @Override
    public Vec3 getVertexOrigin() {
        return this.vertexOrigin;
    }

    @Override
    public boolean useVertexPointAttrib(DrawContext dc, int attribLocation) {
        boolean bufferBound = (this.vertexPoints != null && this.vertexPoints.bindBuffer(dc));
        if (bufferBound) {
            Platform.getGL().glVertexAttribPointer(attribLocation, 3, GL.GL_FLOAT, false, 0, 0);
        }

        return bufferBound;
    }

    @Override
    public boolean useVertexTexCoordAttrib(DrawContext dc, int attribLocation) {
        boolean bufferBound = (this.vertexTexCoords != null && this.vertexTexCoords.bindBuffer(dc));
        if (bufferBound){
            Platform.getGL().glVertexAttribPointer(attribLocation, 2, GL.GL_FLOAT, false, 0, 0);
        }

        return bufferBound;
    }

    @Override
    public boolean drawLines(DrawContext dc) {
        boolean bufferBound = (this.elements != null && this.elements.bindBuffer(dc));
        if (bufferBound) {
            Platform.getGL().glDrawElements(GL.GL_LINES, this.lineElementRange.length(), GL.GL_UNSIGNED_SHORT,
                this.lineElementRange.lower * 2);
        }

        return bufferBound;
    }

    @Override
    public boolean drawTriangles(DrawContext dc) {
        boolean bufferBound = (this.elements != null && this.elements.bindBuffer(dc));
        if (bufferBound) {
            Platform.getGL().glDrawElements(GL.GL_TRIANGLE_STRIP, this.triStripElementRange.length(), GL.GL_UNSIGNED_SHORT,
                this.triStripElementRange.lower * 2);
        }

        return bufferBound;
    }

    @Override
    public void draw(DrawContext dc) {
        this.drawTriangles(dc);
    }
}
