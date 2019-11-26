package gov.nasa.worldwind;

import com.sun.javafx.scene.NodeHelper;
import com.sun.javafx.stage.WindowHelper;
import gov.nasa.worldwind.draw.DrawContext;
import gov.nasa.worldwind.geom.Line;
import gov.nasa.worldwind.geom.Matrix4;
import gov.nasa.worldwind.geom.Vec2;
import gov.nasa.worldwind.geom.Vec3;
import gov.nasa.worldwind.geom.Viewport;
import gov.nasa.worldwind.globe.BasicTessellator;
import gov.nasa.worldwind.globe.Globe;
import gov.nasa.worldwind.globe.ProjectionWgs84;
import gov.nasa.worldwind.globe.Tessellator;
import gov.nasa.worldwind.input.MotionEvent;
import gov.nasa.worldwind.layer.LayerList;
import gov.nasa.worldwind.platform.EGL;
import gov.nasa.worldwind.platform.Platform;
import gov.nasa.worldwind.render.RenderContext;
import gov.nasa.worldwind.render.RenderResourceCache;
import gov.nasa.worldwind.util.Logger;
import gov.nasa.worldwind.util.MessageListener;
import gov.nasa.worldwind.util.Pool;
import gov.nasa.worldwind.util.SynchronizedPool;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Region;

import java.util.Map;
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;
import java.util.concurrent.TimeUnit;

public class WorldWindNode extends Region implements WorldWindow, MessageListener {

    protected static final int MAX_FRAME_QUEUE_SIZE = 2;

    protected static final int MSG_ID_CLEAR_CACHE = 1;

    protected static final int MSG_ID_REQUEST_REDRAW = 2;

    protected static final int MSG_ID_SET_VIEWPORT = 3;

    protected static final int MSG_ID_SET_DEPTH_BITS = 4;

    protected Globe globe = new Globe(WorldWind.WGS84_ELLIPSOID, new ProjectionWgs84());

    protected LayerList layers = new LayerList();

    protected Tessellator tessellator = new BasicTessellator();

    protected double verticalExaggeration = 1;

    protected double fieldOfView = 45;

    protected Navigator navigator = new Navigator();

    protected NavigatorEventSupport navigatorEvents = new NavigatorEventSupport(this);

    protected FrameController frameController = new BasicFrameController();

    protected FrameMetrics frameMetrics = new FrameMetrics();

    protected WorldWindowController worldWindowController = new BasicWorldWindowController();

    protected RenderResourceCache renderResourceCache;

    protected RenderContext rc = new RenderContext();

    protected DrawContext dc = new DrawContext();

    protected Viewport viewport = new Viewport();

    protected int depthBits;

    protected Pool<Frame> framePool = new SynchronizedPool<>();

    protected Queue<Frame> frameQueue = new ConcurrentLinkedQueue<>();

    protected Queue<Frame> pickQueue = new ConcurrentLinkedQueue<>();

    protected Frame currentFrame;

    private boolean isPaused;

    private boolean isWaitingForRedraw;

    protected Handler mainThreadHandler = new Handler(new Handler.Callback() {
        @Override
        public boolean handleMessage(Message msg) {
            if (msg.what == MSG_ID_CLEAR_CACHE) {
                renderResourceCache.clear();
            } else if (msg.what == MSG_ID_REQUEST_REDRAW) {
                requestRedraw();
            } else if (msg.what == MSG_ID_SET_VIEWPORT) {
                viewport.set((Viewport) msg.obj);
            } else if (msg.what == MSG_ID_SET_DEPTH_BITS) {
                depthBits = (Integer) msg.obj;
            }
            return false;
        }
    });

    private Matrix4 scratchModelview = new Matrix4();

    private Matrix4 scratchProjection = new Matrix4();

    private Vec3 scratchPoint = new Vec3();

    public WorldWindNode() {
        addEventHandler(MouseEvent.ANY, this::onMouseEvent);
    }

    @Override
    public Globe getGlobe() {
        return globe;
    }

    @Override
    public void setGlobe(Globe globe) {
        if (globe == null) {
            throw new IllegalArgumentException("globe");
        }

        this.globe = globe;
    }

    @Override
    public Tessellator getTessellator() {
        return tessellator;
    }

    @Override
    public void setTessellator(Tessellator tessellator) {
        if (tessellator == null) {
            throw new IllegalArgumentException("tesselator");
        }

        this.tessellator = tessellator;
    }

    @Override
    public LayerList getLayers() {
        return layers;
    }

    @Override
    public void setLayers(LayerList layers) {
        if (layers == null) {
            throw new IllegalArgumentException("layers");
        }

        this.layers = layers;
    }

    @Override
    public double getVerticalExaggeration() {
        return verticalExaggeration;
    }

    @Override
    public void setVerticalExaggeration(double verticalExaggeration) {
        if (verticalExaggeration <= 0) {
            throw new IllegalArgumentException("verticalExaggeration");
        }

        this.verticalExaggeration = verticalExaggeration;
    }

    @Override
    public double getFieldOfView() {
        return fieldOfView;
    }

    @Override
    public void setFieldOfView(double fovyDegrees) {
        if (fovyDegrees <= 0 || fovyDegrees >= 180) {
            throw new IllegalArgumentException("fovyDegrees");
        }

        this.fieldOfView = fovyDegrees;
    }

    @Override
    public Navigator getNavigator() {
        return navigator;
    }

    @Override
    public void setNavigator(Navigator navigator) {
        if (navigator == null) {
            throw new IllegalArgumentException("navigator");
        }

        this.navigator = navigator;
    }

    @Override
    public void addNavigatorListener(NavigatorListener listener) {
        if (listener == null) {
            throw new IllegalArgumentException("listener");
        }

        navigatorEvents.addNavigatorListener(listener);
    }

    @Override
    public void removeNavigatorListener(NavigatorListener listener) {
        if (listener == null) {
            throw new IllegalArgumentException("listener");
        }

        navigatorEvents.removeNavigatorListener(listener);
    }

    @Override
    public long getNavigatorStoppedDelay() {
        return navigatorEvents.getNavigatorStoppedDelay();
    }

    @Override
    public void setNavigatorStoppedDelay(long delay, TimeUnit unit) {
        navigatorEvents.setNavigatorStoppedDelay(delay, unit);
    }

    @Override
    public FrameController getFrameController() {
        return frameController;
    }

    @Override
    public void setFrameController(FrameController frameController) {
        if (frameController == null) {
            throw new IllegalArgumentException("frameController");
        }

        this.frameController = frameController;
    }

    @Override
    public FrameMetrics getFrameMetrics() {
        return frameMetrics;
    }

    @Override
    public void setFrameMetrics(FrameMetrics frameMetrics) {
        if (frameMetrics == null) {
            throw new IllegalArgumentException("frameMetrics");
        }

        this.frameMetrics = frameMetrics;
    }

    @Override
    public WorldWindowController getWorldWindowController() {
        return worldWindowController;
    }

    @Override
    public void setWorldWindowController(WorldWindowController controller) {
        if (controller == null) {
            throw new IllegalArgumentException("controller");
        }

        this.worldWindowController.setWorldWindow(null); // detach the old controller
        this.worldWindowController = controller; // switch to the new controller
        this.worldWindowController.setWorldWindow(this); // attach the new controller
    }

    @Override
    public RenderResourceCache getRenderResourceCache() {
        return renderResourceCache;
    }

    @Override
    public void setRenderResourceCache(RenderResourceCache cache) {
        if (cache == null) {
            throw new IllegalArgumentException("cache");
        }

        this.renderResourceCache = cache;
    }

    @Override
    public PickedObjectList pick(float x, float y) {
        // Allocate a list in which to collect and return the picked objects.
        PickedObjectList pickedObjects = new PickedObjectList();

        // Nothing can be picked if the WorldWindow's OpenGL thread is paused.
        if (this.isPaused) {
            return pickedObjects;
        }

        // Compute the pick point in OpenGL screen coordinates, rounding to the nearest whole pixel. Nothing can be picked
        // if pick point is outside the WorldWindow's viewport.
        int px = Math.round(x);
        int py = Math.round(this.getViewHeight() - y);
        if (!this.viewport.contains(px, py)) {
            return pickedObjects;
        }

        // Compute the line in Cartesian coordinates that passes through the pick point. Nothing can be picked if the
        // line cannot be constructed.
        Line pickRay = new Line();
        if (!this.rayThroughScreenPoint(x, y, pickRay)) { // use the original XY coordinates for the pick ray
            return pickedObjects;
        }

        // Obtain a frame from the pool and render the frame, accumulating Drawables to process in the OpenGL thread.
        Frame frame = Frame.obtain(this.framePool);
        frame.pickedObjects = pickedObjects;
        frame.pickViewport = new Viewport(px - 1, py - 1, 3, 3); // 3x3 viewport centered on the pick point
        frame.pickViewport.intersect(this.viewport); // limit the 3x3 viewport to the screen viewport
        frame.pickPoint = new Vec2(px, py);
        frame.pickRay = pickRay;
        frame.pickMode = true;
        this.renderFrame(frame);

        // Wait until the OpenGL thread is done processing the frame and resolving the picked objects.
        frame.awaitDone();

        return pickedObjects;
    }

    @Override
    public PickedObjectList pickShapesInRect(float x, float y, float width, float height) {
        // Allocate a list in which to collect and return the picked objects.
        PickedObjectList pickedObjects = new PickedObjectList();

        // Nothing can be picked if the WorldWindow's OpenGL thread is paused.
        if (this.isPaused) {
            return pickedObjects;
        }

        int px = (int) Math.floor(x);
        int py = (int) Math.floor(this.getHeight() - (y + height));
        int pw = (int) Math.ceil(width);
        int ph = (int) Math.ceil(height);
        if (!this.viewport.intersects(px, py, pw, ph)) {
            return pickedObjects;
        }

        // Obtain a frame from the pool and render the frame, accumulating Drawables to process in the OpenGL thread.
        Frame frame = Frame.obtain(this.framePool);
        frame.pickedObjects = pickedObjects;
        frame.pickViewport = new Viewport(px, py, pw, ph); // caller-specified pick rectangle
        frame.pickViewport.intersect(this.viewport); // limit the pick viewport to the screen viewport
        frame.pickMode = true;
        this.renderFrame(frame);

        // Wait until the OpenGL thread is done processing the frame and resolving the picked objects.
        frame.awaitDone();

        return pickedObjects;
    }

    @Override
    public boolean cartesianToScreenPoint(double x, double y, double z, Vec2 result) {
        if (result == null) {
            throw new IllegalArgumentException("result");
        }

        // Compute the WorldWindow's modelview-projection matrix.
        this.computeViewingTransform(this.scratchProjection, this.scratchModelview);
        this.scratchProjection.multiplyByMatrix(this.scratchModelview);

        // Transform the Cartesian point to OpenGL screen coordinates. Complete the transformation by converting to
        // Android screen coordinates and discarding the screen Z component.
        if (this.scratchProjection.project(x, y, z, this.viewport, this.scratchPoint)) {
            result.x = (float) this.scratchPoint.x;
            result.y = (float) (this.getHeight() - this.scratchPoint.y);
            return true;
        }

        return false;
    }

    @Override
    public boolean geographicToScreenPoint(double latitude, double longitude, double altitude, Vec2 result) {
        if (result == null) {
            throw new IllegalArgumentException("result");
        }

        // Convert the position from geographic coordinates to Cartesian coordinates.
        this.globe.geographicToCartesian(latitude, longitude, altitude, this.scratchPoint);

        // Convert the position from Cartesian coordinates to screen coordinates.
        return this.cartesianToScreenPoint(this.scratchPoint.x, this.scratchPoint.y, this.scratchPoint.z, result);
    }

    @Override
    public boolean rayThroughScreenPoint(float x, float y, Line result) {
        if (result == null) {
            throw new IllegalArgumentException("result");
        }

        // Convert from Android screen coordinates to OpenGL screen coordinates by inverting the Y axis.
        double sx = x;
        double sy = this.getHeight() - y;

        // Compute the inverse modelview-projection matrix corresponding to the WorldWindow's current Navigator state.
        this.computeViewingTransform(this.scratchProjection, this.scratchModelview);
        this.scratchProjection.multiplyByMatrix(this.scratchModelview).invert();

        // Transform the screen point to Cartesian coordinates at the near and far clip planes, store the result in the
        // ray's origin and direction, respectively. Complete the ray direction by subtracting the near point from the
        // far point and normalizing.
        if (this.scratchProjection.unProject(sx, sy, this.viewport, result.origin /*near*/, result.direction /*far*/)) {
            result.direction.subtract(result.origin).normalize();
            return true;
        }

        return false;
    }

    @Override
    public double pixelSizeAtDistance(double distance) {
        double tanfovy_2 = Math.tan(Math.toRadians(this.fieldOfView * 0.5));
        double frustumHeight = 2 * distance * tanfovy_2;
        return frustumHeight / this.getHeight();
    }

    @Override
    public double distanceToViewGlobeExtents() {
        double sinfovy_2 = Math.sin(Math.toRadians(this.fieldOfView * 0.5));
        double radius = this.globe.getEquatorialRadius();
        return radius / sinfovy_2 - radius;
    }

    @Override
    public void requestRedraw() {
        // Forward calls to requestRedraw to the main thread.
        if (javafx.application.Platform.isFxApplicationThread()) {
            this.mainThreadHandler.sendEmptyMessage(MSG_ID_REQUEST_REDRAW /*what*/);
            return;
        }

        // Suppress duplicate redraw requests, request that occur while the WorldWindow is paused, and requests that
        // occur before we have an Android surface to draw to.
        if (!this.isWaitingForRedraw && !this.isPaused && !this.viewport.isEmpty()) {
            javafx.application.Platform.runLater(doFrameMethod);
            this.isWaitingForRedraw = true;
        }

        NodeHelper.getNodeAccessor().getPeer(this).markDirty();
    }

    private final Runnable doFrameMethod = this::doFrame;

    private void doFrame() {
        // Skip frames when OpenGL thread has fallen two or more frames behind. Continue to request frame callbacks
        // until the OpenGL thread catches up.
        if (this.frameQueue.size() >= MAX_FRAME_QUEUE_SIZE) {
            javafx.application.Platform.runLater(doFrameMethod);
            return;
        }

        // Allow subsequent redraw requests.
        this.isWaitingForRedraw = false;

        // Obtain a frame from the pool and render the frame, accumulating Drawables to process in the OpenGL thread.
        // The frame is recycled by the OpenGL thread.
        try {
            Frame frame = Frame.obtain(this.framePool);
            this.renderFrame(frame);
        } catch (Exception e) {
            Logger.logMessage(Logger.ERROR, "WorldWindNode", "doFrame",
                "Exception while rendering frame.", e);
        }
    }

    @Override
    public int getViewWidth() {
        return (int)getWidth();
    }

    @Override
    public int getViewHeight() {
        return (int)getHeight();
    }

    private void onMouseEvent(MouseEvent event) {
        MotionEvent motionEvent = new MotionEvent(
            new int[] {0}, new int[] {(int)event.getX()}, new int[] {(int)event.getY()});

        try {
            if (this.worldWindowController.onTouchEvent(motionEvent)) {
                this.navigatorEvents.onTouchEvent(motionEvent);
            }
        } catch (Exception e) {
            Logger.logMessage(Logger.ERROR, "WorldWindNode", "onMouseEvent",
                    "Exception while handling mouse event \'" + event + "\'", e);
        }
    }

    @Override
    public void onMessage(String name, Object sender, Map<Object, Object> userProperties) {
        if (name.equals(WorldWind.REQUEST_REDRAW)) {
            this.requestRedraw(); // may be called on any thread
        }
    }

    private void renderFrame(Frame frame) {
        // Mark the beginning of a frame render.
        boolean pickMode = frame.pickMode;
        if (!pickMode) {
            this.frameMetrics.beginRendering(this.rc);
        }

        // Setup the render context according to the WorldWindow's current state.
        this.rc.globe = this.globe;
        this.rc.terrainTessellator = this.tessellator;
        this.rc.layers = this.layers;
        this.rc.verticalExaggeration = this.verticalExaggeration;
        this.rc.fieldOfView = this.fieldOfView;
        this.rc.horizonDistance = this.globe.horizonDistance(this.navigator.getAltitude());
        this.rc.camera = this.navigator.getAsCamera(this.globe, this.rc.camera);
        this.rc.cameraPoint = this.globe.geographicToCartesian(this.rc.camera.latitude, this.rc.camera.longitude, this.rc.camera.altitude, this.rc.cameraPoint);
        this.rc.renderResourceCache = this.renderResourceCache;

        // TODO
        //this.rc.renderResourceCache.setResources(Platform.getResources());
        //this.rc.resources = Platform.getResources();

        // Configure the frame's Cartesian modelview matrix and eye coordinate projection matrix.
        this.computeViewingTransform(frame.projection, frame.modelview);
        frame.viewport.set(this.viewport);
        frame.infiniteProjection.setToInfiniteProjection(this.viewport.width, this.viewport.height, this.fieldOfView, 1.0);
        frame.infiniteProjection.multiplyByMatrix(frame.modelview);
        this.rc.viewport.set(frame.viewport);
        this.rc.projection.set(frame.projection);
        this.rc.modelview.set(frame.modelview);
        this.rc.modelviewProjection.setToMultiply(frame.projection, frame.modelview);
        if (pickMode) {
            this.rc.frustum.setToModelviewProjection(frame.projection, frame.modelview, frame.viewport, frame.pickViewport);
        } else {
            this.rc.frustum.setToModelviewProjection(frame.projection, frame.modelview, frame.viewport);
        }

        // Accumulate the Drawables in the frame's drawable queue and drawable terrain data structures.
        this.rc.drawableQueue = frame.drawableQueue;
        this.rc.drawableTerrain = frame.drawableTerrain;
        this.rc.pickedObjects = frame.pickedObjects;
        this.rc.pickViewport = frame.pickViewport;
        this.rc.pickPoint = frame.pickPoint;
        this.rc.pickRay = frame.pickRay;
        this.rc.pickMode = frame.pickMode;

        // Let the frame controller render the WorldWindow's current state.
        this.frameController.renderFrame(this.rc);

        // Enqueue the frame for processing on the OpenGL thread as soon as possible and wake the OpenGL thread.
        if (pickMode) {
            this.pickQueue.offer(frame);
            NodeHelper.getNodeAccessor().getPeer(this).markDirty();
        } else {
            this.frameQueue.offer(frame);
            NodeHelper.getNodeAccessor().getPeer(this).markDirty();
        }

        // Propagate redraw requests submitted during rendering. The render context provides a layer of indirection that
        // insulates rendering code from establishing a dependency on a specific WorldWindow.
        if (!pickMode && this.rc.isRedrawRequested()) {
            this.requestRedraw();
        }

        // Notify navigator change listeners when the modelview matrix associated with the frame has changed.
        if (!pickMode) {
            this.navigatorEvents.onFrameRendered(this.rc);
        }

        // Mark the end of a frame render.
        if (!pickMode) {
            this.frameMetrics.endRendering(this.rc);
        }

        // Reset the render context's state in preparation for the next frame.
        this.rc.reset();
    }

    private void drawFrame(Frame frame) {
        // Mark the beginning of a frame draw.
        boolean pickMode = frame.pickMode;
        if (!pickMode) {
            this.frameMetrics.beginDrawing(this.dc);
        }

        // Setup the draw context according to the frame's current state.
        this.dc.eyePoint = frame.modelview.extractEyePoint(this.dc.eyePoint);
        this.dc.viewport.set(frame.viewport);
        this.dc.projection.set(frame.projection);
        this.dc.modelview.set(frame.modelview);
        this.dc.modelviewProjection.setToMultiply(frame.projection, frame.modelview);
        this.dc.infiniteProjection.set(frame.infiniteProjection);
        this.dc.screenProjection.setToScreenProjection(frame.viewport.width, frame.viewport.height);

        // Process the drawables in the frame's drawable queue and drawable terrain data structures.
        this.dc.drawableQueue = frame.drawableQueue;
        this.dc.drawableTerrain = frame.drawableTerrain;
        this.dc.pickedObjects = frame.pickedObjects;
        this.dc.pickViewport = frame.pickViewport;
        this.dc.pickPoint = frame.pickPoint;
        this.dc.pickMode = frame.pickMode;

        // Let the frame controller draw the frame.
        this.frameController.drawFrame(this.dc);

        // Release resources evicted during the previous frame.
        this.renderResourceCache.releaseEvictedResources(this.dc);

        // Mark the end of a frame draw.
        if (!pickMode) {
            this.frameMetrics.endDrawing(this.dc);
        }

        // Reset the draw context's state in preparation for the next frame.
        this.dc.reset();
    }

    private void computeViewingTransform(Matrix4 projection, Matrix4 modelview) {
        // Compute the clip plane distances. The near distance is set to a large value that does not clip the globe's
        // surface. The far distance is set to the smallest value that does not clip the atmosphere.
        // TODO adjust the clip plane distances based on the navigator's orientation - shorter distances when the
        // TODO horizon is not in view
        // TODO parameterize the object altitude for horizon distance
        double eyeAltitude = this.navigator.getAltitude();
        double eyeHorizon = this.globe.horizonDistance(eyeAltitude);
        double atmosphereHorizon = this.globe.horizonDistance(160000);
        double near = eyeAltitude * 0.5;
        double far = eyeHorizon + atmosphereHorizon;

        // Computes the near clip distance that provides a minimum resolution at the far clip plane, based on the OpenGL
        // context's depth buffer precision.
        if (this.depthBits != 0) {
            double maxDepthValue = (1 << this.depthBits) - 1;
            double farResolution = 10.0;
            double nearDistance = far / (maxDepthValue / (1 - farResolution / far) - maxDepthValue + 1);
            // Use the computed near distance only when it's less than our default distance.
            if (near > nearDistance) {
                near = nearDistance;
            }
        }

        // Compute a perspective projection matrix given the WorldWindow's viewport, field of view, and clip distances.
        projection.setToPerspectiveProjection(this.viewport.width, this.viewport.height, this.fieldOfView, near, far);

        // Compute a Cartesian transform matrix from the Navigator.
        this.navigator.getAsViewingMatrix(this.globe, modelview);
    }

}
