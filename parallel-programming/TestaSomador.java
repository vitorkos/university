import java.util.Random;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TestaSomador {
    private static final ExecutorService pool =
        Executors.newFixedThreadPool(3);

    public static void main(String[] args) throws InterruptedException, ExecutionException {
        int QUANTIDADE = 1_000_000;
        Integer v1[] = new Integer[QUANTIDADE];
        Random gerador = new Random();

        for(int i = 0; i < QUANTIDADE; i++){
            v1[i] = gerador.nextInt();
        }

        Integer v2[] = new Integer[QUANTIDADE];
        for(int i = 0; i < QUANTIDADE; i++){
            v2[i] = gerador.nextInt();
        }

        Integer v3[] = new Integer[QUANTIDADE];
        for(int i = 0; i < QUANTIDADE; i++){
            v3[i] = gerador.nextInt();
        }

        long inicio = System.currentTimeMillis();
        Somador s1 = new Somador(v1);
        Somador s2 = new Somador(v2);
        Somador s3 = new Somador(v3);

        Future<Integer> futuro = pool.submit(s1);
        Future<Integer> futuro2 = pool.submit(s2);
        Future<Integer> futuro3 = pool.submit(s3);

        System.out.println(futuro.get() + futuro2.get() +futuro3.get());
        pool.shutdown();


    }
}
