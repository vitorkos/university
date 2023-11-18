package app;

import java.io.IOException;
import javafx.application.Platform;
import javafx.fxml.FXML;


public class MenuController {
    
    @FXML
    private void registerDriver() throws IOException {
        App.setRoot("newDriver");
    }
    
    @FXML
    private void registerOperator() throws IOException {
        App.setRoot("newOperator");
    }
    
    @FXML
    private void sair(){
        Platform.exit();
        System.exit(0);
    }
    
}