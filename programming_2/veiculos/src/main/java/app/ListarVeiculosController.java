package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.Veiculo;
import util.Dao;

import java.io.IOException;
import java.util.List;

public class ListarVeiculosController {
  @FXML
  private ListView<String> vehicles;

  private Dao<Veiculo> dao;

  @FXML
  private void initialize() {
    dao = new Dao(Veiculo.class);
    List<Veiculo> vehiclesList = dao.getAll();
    List<String> vehicles = FXCollections.observableArrayList();
    for (Veiculo vehicle : vehiclesList) {
      vehicles.add(vehicle.getBrand() + " " + vehicle.getModel() + " " + vehicle.getPlate());
    }
    this.vehicles.getItems().addAll(vehicles);
  }

    @FXML
    private void goToMenu() throws IOException {
        App.setRoot("menu");
    }
}
