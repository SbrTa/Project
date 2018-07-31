package controller;
import entity.*;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import main.Main;
import main.createHibernateSession;
import org.hibernate.Query;
import org.hibernate.Session;

import java.io.IOException;
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

    @FXML private TextField searchTextField;
    @FXML Button searchButtonID;
    private int item=0;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle){

        searchTextField.setVisible(false);
        searchButtonID.setVisible(false);

        firstName.setCellValueFactory(new PropertyValueFactory<Student, String>("firstName"));
        lastName.setCellValueFactory(new PropertyValueFactory<Student, String>("lastName"));
        dept.setCellValueFactory(new PropertyValueFactory<Student, String>("dept"));
        id.setCellValueFactory(new PropertyValueFactory<Student, String>("sid"));
        phone.setCellValueFactory(new PropertyValueFactory<Student, String>("phone"));
        email.setCellValueFactory(new PropertyValueFactory<Student, String>("email"));

        tableView.setItems(getAllStudent());
    }

    public ObservableList<Student> getAllStudent(){
        Session session = createHibernateSession.hibernateSession();
        List<Student> studentList = session.createCriteria(Student.class).list();
        ObservableList<Student> studentObservableList = FXCollections.observableList(studentList);
        return studentObservableList;
    }

    @FXML private void searchByNameItem() throws Exception{
        //tableView.setItems(getAllStudent());
        searchTextField.setPromptText("Enter Name");
        searchTextField.setVisible(true);
        searchButtonID.setVisible(true);
        item=0;
    }

    @FXML private void searchButton() throws Exception{
        System.out.println("Search Button........");
        String name = searchTextField.getText();
        System.out.println(name);
        //tableView.setItems(getAllStudentbyName(name));

    }


    public ObservableList<Student> getAllStudentbyName(String name) throws Exception{
        Session session = createHibernateSession.hibernateSession();
        Query query = session.createQuery("FROM student where firstName = :name");
        query.setParameter("name",1);
        List<Student> studentList = query.list();
        for (Student student : studentList){
            System.out.println(student);
        }
        ObservableList<Student> studentObservableList = FXCollections.observableList(studentList);
        return studentObservableList;
    }



    @FXML private void backButton() throws IOException {
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/home.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
    }





}
