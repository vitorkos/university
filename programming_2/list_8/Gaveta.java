package list_8;

public class Gaveta<T> {
    T conteudo;

    public Gaveta(){
        this.conteudo = null;
    }

    public Gaveta(T conteudo) {
        this.conteudo = conteudo;
    }
    
    public void setConteudo(T conteudo) {
        this.conteudo = conteudo;
    }

    public T getConteudo() {
        return this.conteudo;
    }
}
