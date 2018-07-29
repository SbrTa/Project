package main;

import javafx.fxml.FXML;
import javafx.scene.control.TextField;

public class addStudentController {
    @FXML private TextField firstNameTF;
    @FXML private TextField lastNameTF;
    @FXML private TextField deptTF;
    @FXML private TextField idTF;
    @FXML private TextField phoneTF;
    @FXML private TextField emailTF;

    @FXML private void registerButton(){
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


    }
}
