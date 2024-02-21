package app;

import java.io.IOException;

import app.App;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.TextField;
import model.Veiculo;
import util.Dao;

public class CriarVeiculoController {
    @FXML
    private TextField brand;

    @FXML
    private TextField model;

    @FXML
    private TextField plate;

    @FXML
    private void createVehicle(){
        Veiculo vehicle = new Veiculo();

        vehicle.setBrand(brand.getText());
        vehicle.setModel(model.getText());
        vehicle.setPlate(plate.getText());

        Dao<Veiculo> dao = new Dao(Veiculo.class);
        dao.insert(vehicle);

        cleanInputs();

        Alert alert = new Alert(AlertType.CONFIRMATION);
        alert.setContentText("Veículo cadastrado");
        alert.show();
    }

    @FXML
    private void cleanInputs(){
        brand.setText("");
        model.setText("");
        plate.setText("");
    }

    @FXML
    private void goToMenu() throws IOException{
        App.setRoot("menu");
    }

}

