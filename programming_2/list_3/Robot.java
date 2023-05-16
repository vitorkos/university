package list_3;

class Robot {
    private String name;
    private Dot position;
    Robot(String name, Dot position){
        this.name = name;
        this.position = position;
    }
    Robot(){
        this("", new Dot());
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name = name;
    }
    public Dot getPosition(){
        return position;
    }
    public void setPosition(Dot position){
        this.position = position;
    }
    public void goLeft(){
        position.setX(position.getCoordenateX() - 1);
    }
    public void goRight(){
        position.setX(position.getCoordenateX() + 1);
    }
    public void goUp(){
        position.setY(position.getCoordenateY() + 1);
    }
    public void goDown(){
        position.setY(position.getCoordenateY() - 1);
    }
}
