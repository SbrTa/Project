package main;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.AnnotationConfiguration;

public class createHibernateSession {
    public static Session hibernateSession(){
        AnnotationConfiguration config = new AnnotationConfiguration();
        config.configure("hibernate.cfg.xml");
        SessionFactory factory = config.buildSessionFactory();
        Session session = factory.getCurrentSession();
        session.beginTransaction();
        return session;
    }
}
