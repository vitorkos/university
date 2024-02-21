package app;

import java.io.IOException;
import java.time.LocalDate;
import java.util.Date;
import java.util.List;

import app.App;
import exception.DeleteException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.Alert.AlertType;
import model.Motorista;
import model.Veiculo;
import model.UsoVeiculo;
import util.Dao;

public class RetiradaVeiculoController {

  @FXML
  private ComboBox<Motorista> drivers;

  @FXML
  private ComboBox<Veiculo> vehicles;


  private ObservableList<Motorista> getDriversObservable;
  private  ObservableList<Veiculo> getVehicleObservable;

  private List<Motorista> getDrivers;
  private List<Veiculo> getVehicle;

  private Dao<Motorista> daoDriver;

  private Dao<Veiculo> daoVehicle;

  @FXML
  private DatePicker dateWithdraw;

  private Dao<UsoVeiculo> daoVehicleUse;

  @FXML
  private void initialize() {
    daoDriver = new Dao(Motorista.class);
    daoVehicle = new Dao(Veiculo.class);

    daoVehicleUse = new Dao(UsoVeiculo.class);

    getDrivers = daoDriver.getAll();
    getVehicle = daoVehicle.getAll();

    getDriversObservable = FXCollections.observableArrayList(getDrivers);
    getVehicleObservable = FXCollections.observableArrayList(getVehicle);

    drivers.setItems(getDriversObservable);
    vehicles.setItems(getVehicleObservable);
  }

  @FXML
  private void withdrawVehicle() {
    Motorista tempDriver = drivers.getSelectionModel().getSelectedItem();
    Veiculo tempVehicle = vehicles.getSelectionModel().getSelectedItem();
    LocalDate date = dateWithdraw.getValue();

    try {
      UsoVeiculo vehicleUse = new UsoVeiculo();
      vehicleUse.setDriver(tempDriver);
      vehicleUse.setVehicle(tempVehicle);
      vehicleUse.setWithdraw(date);
      vehicleUse.setDevolution(null);
      daoVehicleUse.insert(vehicleUse);

      Alert alert = new Alert(AlertType.CONFIRMATION);
      alert.setContentText("Veículo retirado com sucesso!");
      alert.show();
      } catch (Exception e) {
        Alert alert = new Alert(AlertType.ERROR);
        alert.setContentText("Não foi possível retirar o veículo");
        alert.show();
    }
  }

  @FXML
  private void goToMenu() throws IOException{
    App.setRoot("menu");
  }

}
