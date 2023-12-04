package exercise_exception;

class TesteException extends Exception{
    public static void main(String[] args) {
        System.out.println("Início do main");
        metodo1();
        System.out.println("Fim do main");
    }
    public static void metodo1(){
        System.out.println("Início do metodo1");
        metodo2();
        System.out.println("Fim do metodo1");
    }
    public static void metodo2(){
        System.out.println("Início do metodo2");
        int[] array = new int[10];
        for (int i = 0; i <= 15; i++) {
            try {
                array[i] = i;
                System.out.println(i);
            } catch (ArrayIndexOutOfBoundsException e) {
                System.out.println("Erro: " + e);
            }
        }
        System.out.println("Fim do metodo2");
    }
    
}
