package list_7;

public class Teste2 {
    public static void main(String[] args) {
        Contacorrente c = new Contacorrente(1000);
        c.depositar(100);
        c.sacar(200);
        System.out.println(c.obterSaldo());
        Contapoupanca t = new Contapoupanca(1000);
        System.out.println(c.calcularTributos());
    }
}
