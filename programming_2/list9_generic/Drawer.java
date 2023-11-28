public class Drawer<T> {
    private T content;

    public Drawer() {
        content = null;
    }

    public Drawer(T content) {
        this.content = content;
    }

    public void setContent(T content) {
        this.content = content;
    }

    public T getContent(){
        return this.content;
    }

    public static void main(String[] args) {
        Drawer<String> drawer = new Drawer<>("Oi");
    }
}