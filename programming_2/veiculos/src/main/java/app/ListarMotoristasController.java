package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.Motorista;
import util.Dao;

import java.io.IOException;
import java.util.List;

public class ListarMotoristasController {
  @FXML
  private ListView<String> drivers;

  private Dao<Motorista> dao;

  @FXML
  private void initialize() {
    dao = new Dao(Motorista.class);
    List<Motorista> driversList = dao.getAll();
    List<String> drivers = FXCollections.observableArrayList();
    for (Motorista driver : driversList) {
      drivers.add(driver.getName() + " " + driver.getCnh());
    }
    this.drivers.getItems().addAll(drivers);
  }

    @FXML
    private void goToMenu() throws IOException {
        App.setRoot("menu");
    }
}
