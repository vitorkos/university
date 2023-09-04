package list_7;

public class Gerenciador {
    public static double calcular(ITributavel ... tributaveis){
        double total = 0;
        for (ITributavel t : tributaveis) {
            total += t.calcularTributos();
        }
        return total;
    }
}
