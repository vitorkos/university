package model;

import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.DiscriminatorValue;
import javax.persistence.Entity;
import javax.persistence.Table;

@Entity
@Table(name = "driver")
@DiscriminatorValue("D")
public class Driver extends Person {

    @Column
    private String cnh;

    @Column(length = 5)
    private String cnhCategory;

    @Column(length = 15)
    private String sector;

    public Driver() {
    }

    public Driver(String cnh, String cnhCategory, String sector, String name, String cpf, String rg, String phone, String email, String address) {
        super(name, address);
        this.cnh = cnh;
        this.cnhCategory = cnhCategory;
        this.sector = sector;
    }

    public String getCnh() {
        return cnh;
    }

    public void setCnh(String cnh) {
        this.cnh = cnh;
    }

    public String getCnhCategory() {
        return cnhCategory;
    }

    public void setCnhCategory(String cnhCategory) {
        this.cnhCategory = cnhCategory;
    }

    public String getSector() {
        return sector;
    }

    public void setSector(String sector) {
        this.sector = sector;
    }

    @Override
    public int hashCode(){
        int hash = 3;
        hash = 53 * hash + Objects.hashCode(this.cnh);
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
        final Driver other = (Driver) obj;
        return Objects.equals(this.cnh, other.cnh);
    }
}
