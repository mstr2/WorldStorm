package gov.nasa.worldwindx;

import javafx.application.Application;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public abstract class JavaFXApplication extends Application {

    @Override
    public void start(Stage primaryStage) {
        Scene scene = new Scene(initialize());
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    protected abstract Parent initialize();

}
