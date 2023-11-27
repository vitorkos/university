package list_4;

class Gaspump {
    private Double tank, price_liter, liters_sold, sale_values;
    Gaspump(){
        tank = 5000.0;
        price_liter = 5.20;
        liters_sold = 0.0;
        sale_values = 0.0;
    }
    public void setTank(Double n){
        tank = n;
    }
    public void setPriceliter(Double n){
        price_liter = n;
    }
    public void setLitersSold(Double n){
        liters_sold = n;
    }
    public void setSalevalues(Double n){
        sale_values = n;
    }
    public Double getTank(){
        return tank;
    }
    public Double getPriceliter(){
        return price_liter;
    }
    public Double getLitersSold(){
        return liters_sold;
    }
    public Double getSaleValues(){
        return sale_values;
    }
    public void supplybyLiter(Double l){
        tank -= l;
        liters_sold += l;
        sale_values += (l * price_liter);
    }
    public void supplybyCash(Double c){
        sale_values+= c;
        liters_sold+= price_liter/c;
        tank -= price_liter/c;
    }
    public Double status(){
        return tank;
    }  
}
