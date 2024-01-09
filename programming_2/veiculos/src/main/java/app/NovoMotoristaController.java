
package app;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import modelo.Motorista;
import util.Dao;

public class NovoMotoristaController {
    @FXML
    private TextField campoNome; 
    
    @FXML
    private TextField campoEndereco; 
    
    @FXML
    private TextField campoCnh; 
    
    @FXML
    private TextField campoCategoria; 
    
    @FXML
    private TextField campoSetor; 
    
    
    
    @FXML
    private void cadastrarMotorista(){
        Motorista motorista = new Motorista();
        motorista.setNome(campoNome.getText());
        motorista.setEndereco(campoEndereco.getText());
        motorista.setCnh(Long.valueOf(campoCnh.getText()));
        motorista.setCategoria(campoCategoria.getText());
        motorista.setSetor(campoSetor.getText());
        Dao<Motorista> dao = new Dao<>(Motorista.class); 
        dao.inserir(motorista);
        limparCampos();
        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Motorista cadastrado");
        alert.show();
    }
    
    @FXML
    private void limparCampos(){
        campoNome.setText("");
        campoEndereco.setText("");
        campoCnh.setText("");
        campoCategoria.setText("");
        campoSetor.setText("");
    }
    
    @FXML
    private void voltarAoMenu() throws IOException{
        App.setRoot("menu");
    }
    
}
