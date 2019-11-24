package gov.nasa.worldwindx;

import gov.nasa.worldwind.WorldWindNode;
import gov.nasa.worldwind.globe.BasicElevationCoverage;
import gov.nasa.worldwind.layer.BackgroundLayer;
import gov.nasa.worldwind.layer.BlueMarbleLandsatLayer;
import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;

public class BasicGlobe extends JavaFXApplication {

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    protected Parent initialize() {
        WorldWindNode node = new WorldWindNode();
        node.getLayers().addLayer(new BackgroundLayer());
        node.getLayers().addLayer(new BlueMarbleLandsatLayer());
        node.getGlobe().getElevationModel().addCoverage(new BasicElevationCoverage());
        node.setBackground(
            new Background(
                new BackgroundFill(
                    Color.RED, new CornerRadii(0), new Insets(0, 0, 0, 0))));
        node.requestRedraw();
        return node;
    }

}
