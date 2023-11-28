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
        drawer.getContent();
        Drawer<Integer> drawer2 = new Drawer<>(2);
        drawer2.setContent(213);
        drawer2.getContent();
        System.out.println(drawer2.getContent());
    }
}