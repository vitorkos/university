
package util;

import java.io.Serializable;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;
import modelo.Operador;

/**
 *
 * @author José 
 * Métodos adicionais específicos de Operador que não existem na classe genérica Dao.java
 */

public class DaoOperador implements Serializable{
    EntityManager manager;
    
    public Operador autenticar(String login, String senha) {
        Operador temp = null;
        manager = JpaUtil.getEntityManager();
        String sql = "SELECT o FROM Operador o WHERE o.login = :login AND o.senha = :senha";
        TypedQuery<Operador> query = manager.createQuery(sql, Operador.class);
        query.setParameter("login", login);
        query.setParameter("senha", senha);
        try {
            temp = query.getSingleResult();
        } catch (Exception e) {  
            temp = null; 
        } finally {
            manager.close();
        }
        return temp;
    }
    
    public boolean jaExiste(String login) {
        Operador temp = null;
        boolean existe = false; 
        manager = JpaUtil.getEntityManager();
        String sql = "SELECT o FROM Operador o WHERE o.login = :login";
        TypedQuery<Operador> query = manager.createQuery(sql, Operador.class);
        query.setParameter("login", login);
        try {
            temp = query.getSingleResult();
            existe = true; 
        } catch (Exception e) {  
            temp = null; 
        } finally {
            manager.close();
        }
        return existe;
    }
    
}
