package app;

import javafx.collections.FXCollections;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import model.UsoVeiculo;
import util.Dao;

import java.io.IOException;
import java.util.List;

public class ListarRetiradasController {
  @FXML
  private ListView<String> withdraws;

  private Dao<UsoVeiculo> dao;

  @FXML
  private void initialize() {
    dao = new Dao(UsoVeiculo.class);
    List<UsoVeiculo> withdrawsList = dao.getAll();
    List<String> withdraws = FXCollections.observableArrayList();
    for (UsoVeiculo withdraw : withdrawsList) {
      withdraws.add(withdraw.getDriver() + " " + withdraw.getVehicle() + " " + withdraw.getWithdraw() + " " + withdraw.getDevolution());
    }
    this.withdraws.getItems().addAll(withdraws);
  }

  @FXML
  private void goToMenu() throws IOException {
    App.setRoot("menu");
  }
}
