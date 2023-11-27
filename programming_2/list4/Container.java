package list_4;

public class Container {
    private Double capacity;
    private Boolean occupied;
    Container(){
        capacity = 0.0;
        occupied=false;
    }
    Container(Double capacity, Boolean occupied){
        this.capacity = capacity;
        this.occupied = occupied;
    }
    public void setCapacity(Double c){
        capacity = c;
    }
    public void setOccupied(Boolean o){
        occupied = o;
    }
    public Double getCapacity(){
        return capacity;
    }
    public Boolean getOccupied(){
        return occupied;
    }
    public Boolean toOccupy(Double content){
        if(content <= capacity){
            occupied = true;
            return true;
        }
        else{
            occupied = false;
            return false;
        }
    }
}
