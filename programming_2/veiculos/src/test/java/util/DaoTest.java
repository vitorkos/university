package util;

import model.Operador;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

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
    public void testInserir(){
        Operador operador = new Operador("Teste", "teste", "teste", "teste");
        Dao<Operador> dao = new Dao(Operador.class);
        dao.insert(operador);
    }
}
