package ui;

import events.EventLogin;
import events.EventPageSignUp;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;

public class PaneLogin extends VBox {
	
	private TextField usernameField;
	private TextField passwordField;
	
	private Button loginButton;
	private Button signUpButton;
	
	private EventLogin eventLogin = new EventLogin(this);
	private EventPageSignUp eventPageSignUp = new EventPageSignUp(this);
	
	public PaneLogin() {
		this.setAlignment(Pos.CENTER);
		this.setSpacing(10);
		this.setMaxWidth(400);
		
		Label usernameLabel = new Label("Username:");
		this.usernameField = new TextField();

		this.getChildren().add(usernameLabel);
		this.getChildren().add(usernameField);
		
		Label passwordLabel = new Label("Password:");
		this.passwordField = new TextField();
		
		this.getChildren().add(passwordLabel);
		this.getChildren().add(passwordField);
		
		this.getChildren().add(this.actionButtons());
	}
	
	public HBox actionButtons() {
		HBox buttons = new HBox();
		buttons.setAlignment(Pos.CENTER);
		buttons.setSpacing(10);

		this.loginButton = new Button("Login");
		this.loginButton.setPrefSize(100, 20);
		this.loginButton.setOnAction(this.eventLogin);
		buttons.getChildren().add(this.loginButton);

		this.signUpButton = new Button("Sign Up");
		this.signUpButton.setPrefSize(100, 20);
		this.signUpButton.setOnAction(this.eventPageSignUp);
		buttons.getChildren().add(this.signUpButton);
		
		return buttons;
	}
	
	public String getUsername() {
		return usernameField.getText();
	}

	public String getPassword() {
		return passwordField.getText();
	}
	
	public EventLogin getEventLogin() {
		return this.eventLogin;
	}
	
	public EventPageSignUp getEventPageSignUp() {
		return this.eventPageSignUp;
	}

}
