package model;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Date;
import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import util.Persistivel;

@Entity
@Table(name = "vehicle_use")

public class UsoVeiculo implements Serializable, Persistivel {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;

    @JoinColumn(name = "vehicle", referencedColumnName = "id")
    @ManyToOne
    private Veiculo vehicle;

    @JoinColumn(name = "driver", referencedColumnName = "id")
    @ManyToOne
    private Motorista driver;

    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate withdraw;

    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate devolution;

    public UsoVeiculo() {
    }

    public UsoVeiculo(Veiculo vehicle, Motorista driver, LocalDate withdraw, LocalDate devolution) {
        this.vehicle = vehicle;
        this.driver = driver;
        this.withdraw = withdraw;
        this.devolution = devolution;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Veiculo getVehicle() {
        return vehicle;
    }

    public void setVehicle(Veiculo vehicle) {
        this.vehicle = vehicle;
    }

    public Motorista getDriver() {
        return driver;
    }

    public void setDriver(Motorista driver) {
        this.driver = driver;
    }

    public LocalDate getWithdraw() {
        return withdraw;
    }

    public void setWithdraw(LocalDate withdraw) {
        this.withdraw = withdraw;
    }

    public LocalDate getDevolution() {
        return devolution;
    }

    public void setDevolution(LocalDate devolution) {
        this.devolution = devolution;
    }

    /*
    @Override
    public int hashCode() {
        int hash = 7;
        hash = 53 * hash + Objects.hashCode(this.id);
        hash = 53 * hash + Objects.hashCode(this.vehicle);
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
        final UsoVeiculo other = (UsoVeiculo) obj;
        if (!Objects.equals(this.id, other.id)) {
            return false;
        }
        return Objects.equals(this.vehicle, other.vehicle);
    }
*/
}
