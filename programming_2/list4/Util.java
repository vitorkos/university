package list_4;
class Util {
    public static Boolean isOdd(Integer n){
        if(n % 2 == 0){
            return true;
        }
        else{
            return false;
        }
    }
    public static Boolean isNegative(Integer n){
        if(n < 0){
            return true;
        }
        else{
            return false;
        }
    }
    public static Double bigger(Double n1, Double n2){
        if(n1 > n2){
            return n1;
        }
        else{
            return n2;
        }
    }
    public static Integer bigger(Integer ... numbers){
        Integer big = 0;
        for(Integer num : numbers){
            if(num > big){
                big = num;
            }
        }
        return big;
    }
}
