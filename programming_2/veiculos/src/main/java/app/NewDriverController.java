package app;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import model.Driver;
import util.Dao;

public class NewDriverController {
    @FXML
    private TextField nameField;; 
    
    @FXML
    private TextField addressField;; 
    
    @FXML
    private TextField cnhField; 
    
    @FXML
    private TextField cnhCategoryField;; 
    
    @FXML
    private TextField sectorField;; 
    
    
    
    @FXML
    private void cadastrarMotorista(){
        Driver driver = new Driver();
        driver.setName(nameField.getText());
        driver.setAddress(addressField.getText());
        driver.setCnh(String.valueOf(cnhField.getText()));
        driver.setCnh(cnhCategoryField.getText());
        driver.setSector(sectorField.getText());
        Dao<Driver> dao = new Dao<Driver>(Driver.class); 
        dao.inserir(driver);
        limparCampos();
        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Motorista cadastrado");
        alert.show();
    }
    
    @FXML
    private void limparCampos(){
        nameField.setText("");
        addressField.setText("");
        cnhField.setText("");
        cnhCategoryField.setText("");
        sectorField.setText("");
    }

    @FXML
    private void voltarAoMenu() throws IOException{
        App.setRoot("menu");
    }
    
}