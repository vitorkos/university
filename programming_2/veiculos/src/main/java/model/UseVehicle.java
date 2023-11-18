package model;

import java.io.Serializable;
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
import util.Persistent;

@Entity
@Table(name = "use_vehicle")

public class UseVehicle implements Serializable, Persistent {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer code;

    @JoinColumn(name = "vehicle", referencedColumnName = "code")
    @ManyToOne
    private Vehicle vehicle;

    @JoinColumn(name = "driver", referencedColumnName = "code")
    @ManyToOne
    private Driver driver;

    @Column
    @Temporal(TemporalType.DATE)
    private Date requestDate;

    @Column
    @Temporal(TemporalType.DATE)
    private Date returnDate;

    public UseVehicle() {
    }

    public UseVehicle(Vehicle vehicle, Driver driver, Date requestDate, Date returnDate) {
        this.vehicle = vehicle;
        this.driver = driver;
        this.requestDate = requestDate;
        this.returnDate = returnDate;
    }

    public Integer getCode() {
        return code;
    }

    public void setCode(Integer code) {
        this.code = code;
    }

    public Vehicle getVehicle() {
        return vehicle;
    }

    public void setVehicle(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public Driver getDriver() {
        return driver;
    }

    public void setDriver(Driver driver) {
        this.driver = driver;
    }

    public Date getRequestDate() {
        return requestDate;
    }

    public void setRequestDate(Date requestDate) {
        this.requestDate = requestDate;
    }

    public Date getReturnDate() {
        return returnDate;
    }

    public void setReturnDate(Date returnDate) {
        this.returnDate = returnDate;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 53 * hash + Objects.hashCode(this.code);
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
        final UseVehicle other = (UseVehicle) obj;
        if (!Objects.equals(this.code, other.code)) {
            return false;
        }
        return Objects.equals(this.vehicle, other.vehicle);
    }
}
