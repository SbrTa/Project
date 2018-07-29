package main;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class homeController {

    @FXML private void logOutButton() throws Exception{
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/main.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
        System.out.println("log out");
    }

    @FXML private  void addStudentButton() throws Exception{
        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/addStudent.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
        System.out.println("add student");
    }
}
