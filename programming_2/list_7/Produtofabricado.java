package list_7;

import java.util.ArrayList;
import java.util.List;

public class Produtofabricado implements IProdutofabricado {
    private String nome;
    private List<IProduto> ingredientes = new ArrayList<>();

    public Produtofabricado(String nome) {
        this.nome = nome;
    }

    @Override
    public String getNome() {
        return nome;
    }

    @Override
    public double getCusto() {
        double custoTotal = 0.0;
        for (IProduto ingrediente : ingredientes) {
            custoTotal += ingrediente.getCusto();
        }
        return custoTotal;
    }

    @Override
    public int getNumeroIngredientes() {
        return ingredientes.size();
    }

    @Override
    public IProduto getIngrediente(int numero) {
        if (numero >= 0 && numero < ingredientes.size()) {
            return ingredientes.get(numero);
        }
        return null;
    }

    public void adicionarIngrediente(IProduto ingrediente) {
        ingredientes.add(ingrediente);
    }
}
