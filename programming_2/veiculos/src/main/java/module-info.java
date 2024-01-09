module app {
    requires javafx.controls;
    requires javafx.fxml;
    
    requires java.persistence;
    requires org.hibernate.orm.core;
    requires org.postgresql.jdbc;
    requires java.sql;
 
    requires org.junit.jupiter.api;
    
    opens app to javafx.fxml;
    opens modelo to org.hibernate.orm.core;
 
    exports app;
    exports util;
    exports modelo;
}


