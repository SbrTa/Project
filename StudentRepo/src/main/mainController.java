package main;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class mainController {
    public static Stage home;

    public void loginButton() throws IOException {
        System.out.println("log in button clicked...");

        home = Main.stage;
        Parent homeRoot = FXMLLoader.load(getClass().getResource("home.fxml"));
        home.setTitle("Student Repo");
        home.setScene(new Scene(homeRoot));
        home.show();
    }
}
