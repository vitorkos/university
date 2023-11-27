package list_4;
class Dog {
    private String race, name;
    Dog(){
        race = "";
        name = "";
    }
    Dog(String name){
        this.name = "indeterminate";
    }
    Dog(String name, String race){
        this.name=name;
        this.race=race;
    }
    public void setName(String n){
        name = n;
    }
    public void setRace(String n){
        race = n;
    }
    public String getName(){
        return name;
    }
    public String getRace(){
        return race;
    }
    public void bark(){
        System.out.println("auau");
    }
    public void repeatedBark(Integer n){
        if(n < 0){
            System.out.println("auau");
        }
        else if(n > 100){
            System.out.println("invalid parameter");
        }
        else{
            for(int i= 0; i<n; i++){
                System.out.println("auau");
            }
        }
    }  
}
