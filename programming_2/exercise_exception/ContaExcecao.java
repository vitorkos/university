package exercise_exception;

public class ContaExcecao extends Exception{
    double saldo;
    double limite;
    ContaExcecao(){
        saldo = 0.0;
        limite = 0.0;
    }
    ContaExcecao(double n, double nn){
        saldo = n;
        limite = nn;
    }
    void deposita(double n){
        saldo += n;
    }
    void setLimite(int n){
        limite = n;
    }
    void saca(double n){
        saldo -= n;
    }
    public static void main(String[] args) {
        ContaExcecao c = new ContaExcecao(1000, 1000);
        try{
            c.saca(2000);
        }catch(Exception e){
            System.out.println("Saldo insuficiente");
        }
    }
}