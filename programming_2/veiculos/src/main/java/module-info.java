module com.app {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.app to javafx.fxml;
    exports com.app;
}
