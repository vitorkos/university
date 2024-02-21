package app;

import java.io.IOException;

import app.App;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import model.Operador;
import util.Dao;

public class CriarOperadorController {
    @FXML
    private TextField name;

    @FXML
    private TextField address;

    @FXML
    private TextField login;

    @FXML
    private TextField password;


    @FXML
    private void createOperator(){
        Operador operator = new Operador();

        operator.setName(name.getText());
        operator.setAddress(address.getText());
        operator.setLogin(login.getText());
        operator.setPassword(password.getText());

        Dao<Operador> dao = new Dao(Operador.class);
        dao.insert(operator);

        cleanInputs();

        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Operador cadastrado");
        alert.show();
    }

    @FXML
    private void cleanInputs(){
        name.setText("");
        address.setText("");
        login.setText("");
        password.setText("");
    }

    @FXML
    private void goToMenu() throws IOException{
        App.setRoot("menu");
    }

}

