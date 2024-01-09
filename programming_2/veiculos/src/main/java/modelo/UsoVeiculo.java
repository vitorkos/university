package modelo;

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
@Table(name = "uso_veiculo")

public class UsoVeiculo implements Serializable, Persistivel {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer codigo;
    
    @JoinColumn(name = "veiculo", referencedColumnName = "codigo")
    @ManyToOne
    private Veiculo veiculo;
    
    @JoinColumn(name = "motorista", referencedColumnName = "codigo")
    @ManyToOne
    private Motorista motorista; 
    
    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate retirada; 
    
    @Column
    @Temporal(TemporalType.DATE)
    private LocalDate devolucao; 

    public UsoVeiculo() {
    }

    public UsoVeiculo(Veiculo veiculo, Motorista motorista, LocalDate retirada, LocalDate devolucao) {
        this.veiculo = veiculo;
        this.motorista = motorista;
        this.retirada = retirada;
        this.devolucao = devolucao;
    }
    
    public Integer getCodigo() {
        return codigo;
    }

    public void setCodigo(Integer codigo) {
        this.codigo = codigo;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public void setVeiculo(Veiculo veiculo) {
        this.veiculo = veiculo;
    }

    public Motorista getMotorista() {
        return motorista;
    }

    public void setMotorista(Motorista motorista) {
        this.motorista = motorista;
    }

    public LocalDate getRetirada() {
        return retirada;
    }

    public void setRetirada(LocalDate retirada) {
        this.retirada = retirada;
    }

    public LocalDate getDevolucao() {
        return devolucao;
    }

    public void setDevolucao(LocalDate devolucao) {
        this.devolucao = devolucao;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 53 * hash + Objects.hashCode(this.codigo);
        hash = 53 * hash + Objects.hashCode(this.veiculo);
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
        if (!Objects.equals(this.codigo, other.codigo)) {
            return false;
        }
        return Objects.equals(this.veiculo, other.veiculo);
    }

}
