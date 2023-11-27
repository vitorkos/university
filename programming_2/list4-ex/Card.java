package list_4_5;

class Card {
    private Integer balance;
    Card(){
        balance = 10;
    }
    public void load(Integer n){
        balance+= n;
    }
    public void useCredit(){
        if(balance==0){
            System.out.println("NOT ENOUGHT CREDITS: NEED TO RELOAD");
        }
        else{
            balance--;
        }
    }
    public Integer getBalance(){
        return balance;
    }
}
