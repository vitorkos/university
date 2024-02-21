
package util;

import model.Operador;

import java.io.Serializable;
import javax.persistence.EntityManager;
import javax.persistence.TypedQuery;

public class DaoOperator implements Serializable{
    EntityManager manager;

    public Operador login(String login, String password) {
        Operador temp = null;
        try {
          manager = JpaUtil.getEntityManager();
          System.out.println("Login: " + login + " Senha: " + password);
          String sql = "SELECT o FROM Operador o WHERE o.login = :login AND o.password = :password";
          TypedQuery<Operador> query = manager.createQuery(sql, Operador.class);
          query.setParameter("login", login);
          query.setParameter("password", password);
          System.out.println("Query: " + query.toString());
            temp = query.getSingleResult();
        } catch (Exception e) {
            temp = null;
        }
        return temp;
    }

    public boolean alreadyExists(String login) {
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
