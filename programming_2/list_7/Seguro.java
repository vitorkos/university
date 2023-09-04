package list_7;

public class Seguro implements ITributavel {
    private double valor;

    public Seguro(double valor) {
        this.valor = valor;
    }

    @Override
    public double calcularTributos() {
        return this.valor * 0.01;
    }
}
