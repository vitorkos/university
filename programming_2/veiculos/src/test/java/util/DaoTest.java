package util;

//import modelo.Vaca;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import model.Driver;
import model.Operator;
import util.Dao;

/**
 *
 * @author Usuário
 */
public class DaoTest {
    
    public DaoTest() {
    }
    
    @BeforeAll
    public static void setUpClass() {
    }
    
    @AfterAll
    public static void tearDownClass() {
    }
    
    @BeforeEach
    public void setUp() {
    }
    
    @AfterEach
    public void tearDown() {
    }
    
    @Test
    public void testInserirMotorista(){
        Driver driver = new Driver();
        driver.setName("Piolito");
        driver.setAddress("Rua das Couves, n. 0, Bandeirates, PR");
        driver.setCnh("2345678L");
        driver.setCnhCategory("ABC");
        Dao<Driver> dao = new Dao<Driver>(Driver.class);
        dao.inserir(driver);
    }
    
    @Test
    public void testInserirOperador(){ 
        Operator op = new Operator("Rigby", "Parque Encantado",
                "rigby", "123" );
        Dao<Operator> dao = new Dao<Operator>(Operator.class);
        dao.inserir(op);
    }
    
//    @Test
//    public void testListarOperador(){
//        
//    }
    
//    @Test
//    public void testListarMotorista(){
//        Dao<Motorista> dao = new Dao(Motorista.class);
//        List<Motorista> lista = dao.listarTodos();
//        System.out.println("\n\n");
//        for (Motorista m : lista){
//            System.out.println("Nome: " + m.getNome());
//        }
//        System.out.println("\n\n");
//    }
//    
//    @Test
//    public void testInserirVeiculo(){
//        Veiculo veiculo = new Veiculo(); 
//        veiculo.setMarca("Fiat");
//        veiculo.setModelo("Uno");
//        veiculo.setPlaca("ABC5F54");
//        Dao<Veiculo> dao = new Dao(Veiculo.class);
//        dao.inserir(veiculo);
//    }
    
//    @Test
//    public void testInserirRetirada(){
//        UsoVeiculo uso = new UsoVeiculo(); 
//        Dao<Veiculo> daoV = new Dao(Veiculo.class);
//        Dao<Motorista> daoM = new Dao(Motorista.class);
//        Dao<UsoVeiculo> daoU = new Dao(UsoVeiculo.class);
//        Motorista m = daoM.buscarPorCodigo(1);
//        Veiculo v = daoV.buscarPorCodigo(1);
//        uso.setVeiculo(v);
//        uso.setMotorista(m);
//        uso.setRetirada(LocalDate.now());
//        daoU.inserir(uso);
//        
//    }
    
}
