package list_3_2;

class Main{
    public static void main(String[] args){
        System.out.println("DATE EXERCISE");
        Date LocalDate = new Date(2005, 10, 20);
        System.out.println("DATE EXERCISE");
        
        LocalDate.changeDate(LocalDate, 1842);
        System.out.println(LocalDate.getYear());
        
        LocalDate.changeDate(LocalDate, 1842, 5);
        System.out.println(LocalDate.getMonth()+"-"+ LocalDate.getYear());
        
        LocalDate.changeDate(LocalDate, 1842, 5, 22);
        System.out.println(LocalDate.getDay()+"-"+ LocalDate.getMonth()+"-"+LocalDate.getYear());

        System.out.println("UTIL EXERCISE");
        System.out.println(Util.formatDate(LocalDate));

        System.out.println("OBJECTS NUMBER EXERCISE");
        Objects object1 = new Objects();
        Objects object2 = new Objects();
        Objects object3 = new Objects();
        System.out.println(Objects.getObjects());

        System.out.println(("VARARGS EXERCISE"));
        System.out.println(Myclass.mathOperations("SUM", 2, 4, 6));

    
    }
}