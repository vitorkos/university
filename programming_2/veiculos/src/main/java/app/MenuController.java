package app;

import java.io.IOException;
import javafx.application.Platform;
import javafx.fxml.FXML;


public class MenuController {
    
    @FXML
    private void cadastrarMotorista() throws IOException {
        App.setRoot("novoMotorista");
    }
    
    @FXML
    private void cadastrarOperador() throws IOException {
        App.setRoot("novoOperador");
    }
    
    @FXML
    private void excluirMotorista() throws IOException{
        App.setRoot("excluirMotorista");
    }
    
    @FXML
    private void retirarVeiculo() throws IOException{
        App.setRoot("retiradaVeiculo");
    }
    
    @FXML
    private void sair(){
        Platform.exit();
        System.exit(0);
    }
    
}
