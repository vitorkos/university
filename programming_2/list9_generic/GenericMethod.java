public class GenericMethod {
    public static <T extends Number> T sum(T[] vector) {
        T sum = null;
        for (T i : vector) {
            sum = sum + i;
        }
        return sum;
    }
}