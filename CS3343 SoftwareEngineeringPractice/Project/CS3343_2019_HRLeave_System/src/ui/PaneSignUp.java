package ui;

import events.EventPageLogin;
import events.EventSignUp;
import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.util.converter.NumberStringConverter;

public class PaneSignUp extends VBox {

	private TextField usernameField;
	private TextField passwordField;
	private TextField preferredNameField;
	private TextField ageField;
	private RadioButton isManagerRadio;
	private RadioButton isSeniorRadio;

	private EventSignUp eventSignUp = new EventSignUp(this);
	private EventPageLogin eventPageLogin = new EventPageLogin(this);

	public PaneSignUp() {
		this.setAlignment(Pos.CENTER);
		this.setSpacing(10);
		this.setMaxWidth(400);

		// add username
		Label usernameLabel = new Label("Username:");
		this.usernameField = new TextField();
		this.getChildren().add(usernameLabel);
		this.getChildren().add(this.usernameField);

		// add password
		Label passwordLabel = new Label("Password:");
		this.passwordField = new TextField();
		this.getChildren().add(passwordLabel);
		this.getChildren().add(this.passwordField);

		// add preferred name
		Label preferredNameLabel = new Label("Preferred name:");
		this.preferredNameField = new TextField();
		this.getChildren().add(preferredNameLabel);
		this.getChildren().add(this.preferredNameField);

		// add age
		Label ageLabel = new Label("Age:");
		this.ageField = new TextField();
		ageField.setTextFormatter(new TextFormatter<>(new NumberStringConverter()));
		this.getChildren().add(ageLabel);
		this.getChildren().add(this.ageField);

		// add isManager
		this.isManagerRadio = new RadioButton("Are you manager?");
		this.getChildren().add(this.isManagerRadio);
		
		this.isSeniorRadio = new RadioButton("Are you senior employee?");
		this.getChildren().add(this.isSeniorRadio);

		// add buttons
		this.getChildren().add(actionButtons());
	}

	public HBox actionButtons() {
		HBox buttons = new HBox();
		buttons.setAlignment(Pos.CENTER);
		buttons.setSpacing(10);

		Button signUpButton = new Button("Sign Up");
		signUpButton.setPrefSize(100, 20);
		signUpButton.setOnAction(this.eventSignUp);
		buttons.getChildren().add(signUpButton);

		Button cancleButton = new Button("Cancle");
		cancleButton.setPrefSize(100, 20);
		cancleButton.setOnAction(this.eventPageLogin);
		buttons.getChildren().add(cancleButton);

		return buttons;
	}

	public String getUsername() {
		return usernameField.getText();
	}

	public String getPassword() {
		return passwordField.getText();
	}

	public String getPreferredName() {
		return preferredNameField.getText();
	}
	
	public int getAge() {
		// BUG: I have a error of number format exception here  
		if (ageField.getText().isEmpty()) {
			return 0;
		}else {
			return Integer.parseInt(ageField.getText());
		}
	}
	
	public boolean getIsManager() {
		return isManagerRadio.isSelected();
	}
	
	public boolean getIsSenior() {
		return isSeniorRadio.isSelected();
	}
	
	public EventSignUp getEventSignUp() {
		return eventSignUp;
	}
	
	public EventPageLogin getEventPageLogin() {
		return eventPageLogin;
	}
	
	
}
