package app;

import java.io.IOException;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import modelo.Operador;
import util.DaoOperador;

public class LoginController {

    @FXML
    private TextField campoLogin;

    @FXML
    private TextField campoSenha;

    @FXML
    private void autenticar() throws IOException {
        DaoOperador dao = new DaoOperador();
        Operador temp = dao.autenticar(campoLogin.getText(), campoSenha.getText());
        if (temp == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setContentText("Login ou senha inválidos");
            alert.show();
        } else {
            App.setRoot("menu");
        }

    }

}
