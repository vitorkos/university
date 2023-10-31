module com.trabalho {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.trabalho to javafx.fxml;
    exports com.trabalho;
}
