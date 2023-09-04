package list_7;

public class Contacorrente extends Conta implements ITributavel {
    public Contacorrente(double saldoInicial) {
        super(saldoInicial);
    }

    @Override
    public double calcularTributos() {
        return obterSaldo() * 0.21;
    }
}
