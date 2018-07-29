package main;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

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

        System.out.println(firstName);
        System.out.println(lastName);
        System.out.println(dept);
        System.out.println(id);
        System.out.println(phone);
        System.out.println(email);

        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setHeaderText(null);
        alert.setContentText("Registration Successfull..");
        alert.showAndWait();

        Stage stage = Main.stage;
        Parent root = FXMLLoader.load(getClass().getResource("home.fxml"));
        stage.setScene(new Scene(root));
        stage.setTitle("Student Repo");
        stage.show();
    }
}
