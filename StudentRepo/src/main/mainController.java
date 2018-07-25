package main;

import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;

import java.awt.event.ActionEvent;
import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class mainController implements Initializable{
    @Override
    public void initialize(URL url, ResourceBundle rb){}
    @FXML private TextField loginUserName;
    @FXML private PasswordField loginPassword;
    @FXML private Label labelWrongUserPass;

    public static Stage stage;
    @FXML private void loginButton() throws Exception{
        //System.out.println("log in button clicked...");
        String user = loginUserName.getText();
        String pass = loginPassword.getText();
        //System.out.println(user);
        //System.out.println(pass);
        if(user.equals("user") && pass.equals("pass")){
            stage = Main.stage;
            Parent homeRoot = FXMLLoader.load(getClass().getResource("home.fxml"));
            stage.setScene(new Scene(homeRoot));
            stage.setTitle("Student Repo");
            stage.show();
        }
        else {
            System.out.println("no match");
            loginUserName.clear();
            loginPassword.clear();
            labelWrongUserPass.setText("Wrong User name or Password");
        }

    }
}
