package controller;
import entity.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import main.Main;
import main.createHibernateSession;
import org.hibernate.Session;

import java.net.URL;
import java.util.List;
import java.util.ResourceBundle;

public class viewStudentController implements Initializable{

    @FXML private TableView<Student> tableView;
    @FXML private TableColumn<Student,String> firstName;
    @FXML private TableColumn<Student,String> lastName;
    @FXML private TableColumn<Student,String> dept;
    @FXML private TableColumn<Student,String> id;
    @FXML private TableColumn<Student,String> phone;
    @FXML private TableColumn<Student,String> email;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle){
        firstName.setCellValueFactory(new PropertyValueFactory<Student, String>("firstName"));
        lastName.setCellValueFactory(new PropertyValueFactory<Student, String>("lastName"));
        dept.setCellValueFactory(new PropertyValueFactory<Student, String>("dept"));
        id.setCellValueFactory(new PropertyValueFactory<Student, String>("sid"));
        phone.setCellValueFactory(new PropertyValueFactory<Student, String>("phone"));
        email.setCellValueFactory(new PropertyValueFactory<Student, String>("email"));

        tableView.setItems(getStudent());
    }

    public ObservableList<Student> getStudent(){
        Session session = createHibernateSession.hibernateSession();
        List<Student> studentList = session.createCriteria(Student.class).list();
        ObservableList<Student> studentObservableList = FXCollections.observableList(studentList);
        return studentObservableList;
    }

    @FXML private void homeButton() throws Exception{
        System.out.println("view student controller home button...");
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/main.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
        //System.out.println("log out");
    }



}
