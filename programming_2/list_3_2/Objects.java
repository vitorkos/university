package list_3_2;

class Objects {
    private static Integer num_objects = 0;
    public Objects(){
        num_objects++;
    }
    public static Integer getObjects(){
        return num_objects;
    }
}
