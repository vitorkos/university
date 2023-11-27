package list_3;

class Main {
    public static void main(String[] args){
        Dot dot = new Dot(3, 4);
        System.out.println("Coordenates of the dot: (" + dot.getCoordenateX() + " , " + dot.getCoordenateY() + ")");
        
        Robot robot = new Robot("Lil Robot", dot);
        System.out.println("Name : " + robot.getName());
        System.out.println("Position: (" + robot.getPosition().getCoordenateX() + " , " + robot.getPosition().getCoordenateY() + ")");
        
        robot.goDown();
        robot.goRight();
        System.out.println("Position: (" + robot.getPosition().getCoordenateX() + " , " + robot.getPosition().getCoordenateY() + ")");
    }
    
}
