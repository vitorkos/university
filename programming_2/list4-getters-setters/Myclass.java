package list_3_2;

class Myclass {
    public static Integer mathOperations(String operation, Integer... numbers){
        Integer sum = 0;
        Integer mult = 1;
        if (operation == "SUM"){
            for(Integer num : numbers){
                sum += num;
            }
            return sum;
        }
        else if(operation == "MULT"){
            for(Integer num : numbers){
                mult *= num;
            }
            return mult;
        }
        return 0;
    }    
}