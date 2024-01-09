package modelo;

import java.io.Serializable;
import java.util.Objects;
import javax.persistence.Column;
import javax.persistence.DiscriminatorValue;
import javax.persistence.Entity;
import javax.persistence.Table;
import util.Persistivel;

@Entity
@Table(name = "motorista")
@DiscriminatorValue("motorista")
public class Motorista extends Pessoa implements Serializable, Persistivel {
    
    @Column
    private Long cnh;
    
    @Column(length = 5)
    private String categoria; 
    
    @Column(length = 15)
    private String setor; 

    public Motorista() {
    }
    
    public Motorista(Long cnh, String categoria, String setor, String nome, String endereco) {
        super(nome, endereco);
        this.cnh = cnh;
        this.categoria = categoria;
        this.setor = setor;
    }

    public Long getCnh() {
        return cnh;
    }

    public void setCnh(Long cnh) {
        this.cnh = cnh;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria(String categoria) {
        this.categoria = categoria;
    }

    public String getSetor() {
        return setor;
    }

    public void setSetor(String setor) {
        this.setor = setor;
    }

    @Override
    public int hashCode() {
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
        final Motorista other = (Motorista) obj;
        return Objects.equals(this.cnh, other.cnh);
    }
    
    @Override
    public String toString(){
        return this.getNome(); 
    }
    
}
