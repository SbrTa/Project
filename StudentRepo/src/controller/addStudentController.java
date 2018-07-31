package controller;

import main.*;
import entity.*;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import main.Main;
import org.hibernate.Session;

import java.io.IOException;

public class addStudentController {
    @FXML private TextField firstNameTF;
    @FXML private TextField lastNameTF;
    @FXML private TextField deptTF;
    @FXML private TextField idTF;
    @FXML private TextField phoneTF;
    @FXML private TextField emailTF;

    @FXML private void registerButton() throws Exception{
        String firstName = firstNameTF.getText();
        String lastName = lastNameTF.getText();
        String dept = deptTF.getText();
        String id = idTF.getText();
        String phone = phoneTF.getText();
        String email = emailTF.getText();

        /*
        System.out.println(firstName);
        System.out.println(lastName);
        System.out.println(dept);
        System.out.println(id);
        System.out.println(phone);
        System.out.println(email);
        */

        //Save student to db
        Session session = createHibernateSession.hibernateSession();
        Student student = new Student();
        student.setFirstName(firstName);
        student.setLastName(lastName);
        student.setDept(dept);
        student.setSid(id);
        student.setPhone(phone);
        student.setEmail(email);
        session.save(student);
        session.getTransaction().commit();
        //System.out.println("Student Saved");

        //Alert: Student info saved successfully
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setHeaderText(null);
        alert.setContentText("Registration Successfull..");
        alert.showAndWait();

        //Go to home page
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/home.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
    }

    @FXML private void backButton() throws IOException {
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/home.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
    }
}
