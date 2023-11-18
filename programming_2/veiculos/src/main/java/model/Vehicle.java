package model;

import java.io.Serializable;
import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import util.Persistent;

@Entity
@Table(name = "vehicle")
public class Vehicle implements Serializable, Persistent {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer code;
    
    @Column(length = 20)
    private String brand;
    
    @Column(length = 20)
    private String model;
    
    @Column(length = 10)
    private String carPlate;

    public Vehicle() {
    }

    public Vehicle(String brand, String model, String carPlate) {
        this.brand = brand;
        this.model = model;
        this.carPlate = carPlate;
    }
    
    @Override
    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getCarPlate() {
        return carPlate;
    }

    public void setCarPlate(String carPlate) {
        this.carPlate = carPlate;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 41 * hash + Objects.hashCode(this.code);
        hash = 41 * hash + Objects.hashCode(this.carPlate);
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final Vehicle other = (Vehicle) obj;
        if (!Objects.equals(this.carPlate, other.carPlate)) {
            return false;
        }
        return Objects.equals(this.code, other.code);
    }

}
