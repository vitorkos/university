package list_3_2;

class Util {
    public static String formatDate(Date date){
        String formatedString = "" + date.getDay() + "/" + date.getMonth() + "/" + date.getYear();
        return formatedString;
    }
}
