package util;

import java.time.LocalDate;
import java.util.List;

import modelo.Motorista;
import modelo.Operador;
import modelo.UsoVeiculo;
import modelo.Veiculo;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;




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
        Motorista motorista = new Motorista();
        motorista.setNome("Piolito");
        motorista.setEndereco("Rua das Couves, n. 0, Bandeirates, PR");
        motorista.setCnh(2345678L);
        motorista.setCategoria("ABC");
        Dao<Motorista> dao = new Dao<>(Motorista.class);
        dao.inserir(motorista);
    }  
    
    @Test
    public void testInserirOperador(){ 
        Operador op = new Operador("Rigby", "Parque Encantado",
                "rigby", "123" );
        Dao<Operador> dao = new Dao<>(Operador.class);
        dao.inserir(op);
    }
    
//    @Test
//    public void testListarOperador(){
//        
//    }
    
    @Test
    public void testListarMotorista(){
        Dao<Motorista> dao = new Dao<>(Motorista.class);
        List<Motorista> lista = dao.listarTodos();
        System.out.println("\n\n");
        for (Motorista m : lista){
            System.out.println("Nome: " + m.getNome());
        }
        System.out.println("\n\n");
    }
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
