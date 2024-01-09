package app;

import java.io.IOException;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.ComboBox;
import modelo.Motorista;
import util.Dao;
import util.ExclusaoException;

public class ExcluirMotoristaController {

    @FXML
    private ComboBox<Motorista> comboMotoristas;

    private ObservableList<Motorista> listaOb;
    private List<Motorista> lista;
    private Dao<Motorista> dao;

    @FXML
    private void initialize() {
        dao = new Dao<Motorista>(Motorista.class);
        lista = dao.listarTodos();
        listaOb = FXCollections.observableArrayList(lista);
        comboMotoristas.setItems(listaOb);
    }

    @FXML
    private void excluirMotorista() {
        Motorista temp = comboMotoristas.getSelectionModel().getSelectedItem();
        try {
            dao.excluir(temp);            
        } catch (ExclusaoException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setContentText("Motorista não pode ser excluído");
            alert.show();
        }
        // atualiza a lista 
        lista = dao.listarTodos();
        listaOb = FXCollections.observableArrayList(lista);
        comboMotoristas.setItems(listaOb);
    }

    @FXML
    private void voltarAoMenu() throws IOException {
        App.setRoot("menu");
    }

}
