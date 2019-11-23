package gov.nasa.worldwind;

import gov.nasa.worldwind.geom.Line;
import gov.nasa.worldwind.geom.Vec2;
import gov.nasa.worldwind.globe.Globe;
import gov.nasa.worldwind.globe.Tessellator;
import gov.nasa.worldwind.layer.LayerList;
import gov.nasa.worldwind.render.RenderResourceCache;

import java.util.concurrent.TimeUnit;

public interface WorldWindow {

    Globe getGlobe();

    void setGlobe(Globe globe);

    Tessellator getTessellator();

    void setTessellator(Tessellator tessellator);

    LayerList getLayers();

    void setLayers(LayerList layers);

    double getVerticalExaggeration();

    void setVerticalExaggeration(double verticalExaggeration);

    double getFieldOfView();

    void setFieldOfView(double fovyDegrees);

    Navigator getNavigator();

    void setNavigator(Navigator navigator);

    void addNavigatorListener(NavigatorListener listener);

    void removeNavigatorListener(NavigatorListener listener);

    long getNavigatorStoppedDelay();

    void setNavigatorStoppedDelay(long delay, TimeUnit unit);

    FrameController getFrameController();

    void setFrameController(FrameController frameController);

    FrameMetrics getFrameMetrics();

    void setFrameMetrics(FrameMetrics frameMetrics);

    WorldWindowController getWorldWindowController();

    void setWorldWindowController(WorldWindowController controller);

    RenderResourceCache getRenderResourceCache();

    void setRenderResourceCache(RenderResourceCache cache);

    PickedObjectList pick(float x, float y);

    PickedObjectList pickShapesInRect(float x, float y, float width, float height);

    boolean cartesianToScreenPoint(double x, double y, double z, Vec2 result);

    boolean geographicToScreenPoint(double latitude, double longitude, double altitude, Vec2 result);

    boolean rayThroughScreenPoint(float x, float y, Line result);

    double pixelSizeAtDistance(double distance);

    double distanceToViewGlobeExtents();

    void requestRedraw();

    int getViewWidth();

    int getViewHeight();

}
