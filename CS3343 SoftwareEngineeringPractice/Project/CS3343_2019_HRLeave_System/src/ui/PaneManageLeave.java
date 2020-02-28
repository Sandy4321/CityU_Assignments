package ui;

import java.util.ArrayList;
import java.util.Calendar;

import events.EventPageHomePage;
import events.EventTakeLeave;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import user.Employee;
import user.Leave;
import util.Converters;


// WARNING: due to time limitation we are unable to complete this class;
public class PaneManageLeave extends VBox {

	private TextField usernameField;
	private TextField passwordField;
	private TextField preferredNameField;
	private TextField ageField;
	private RadioButton isManagerRadio;
	private RadioButton isSeniorRadio;
	
	private ArrayList<Leave> leaves = new ArrayList<>();
	private ArrayList<RadioButton> approved = new ArrayList<>();

	private EventPageHomePage eventPageHomePage = new EventPageHomePage(this);
	private EventTakeLeave eventTakeLeave = new EventTakeLeave(this);

	public PaneManageLeave(
			ArrayList<Leave> leaves
			) {
		this.setAlignment(Pos.TOP_CENTER);
		this.setSpacing(10);
		this.setMaxWidth(1000);
		
		this.leaves = leaves;
		
		this.getChildren().add(add2Pane());

	}

	public HBox actionButtons() {
		HBox buttons = new HBox();
		buttons.setAlignment(Pos.CENTER);
		buttons.setSpacing(10);

		Button applyButton = new Button("Apply");
		applyButton.setPrefSize(100, 20);
		applyButton.setOnAction(this.eventTakeLeave);
		buttons.getChildren().add(applyButton);

		return buttons;
	}
	
	public HBox add2Pane() {
		HBox panes = new HBox();
		panes.setSpacing(10);
		
		// buttons
		VBox leftPane = new VBox();
		leftPane.setSpacing(10);
		leftPane.setPadding(new Insets(10,10,10,10));
		
		Button backButton = new Button("Back");
		backButton.setOnAction(this.eventPageHomePage);
		leftPane.getChildren().add(backButton);	
		
		leftPane.prefWidthProperty().bind(panes.widthProperty().divide(4));

		VBox rightPane = new VBox();
		rightPane.setSpacing(10);
		
		rightPane.setPadding(new Insets(10,10,10,10));
		
//		Label usernameLabel = new Label("Start:");
//		this.usernameField = new TextField();
//		rightPane.getChildren().add(usernameLabel);
//		rightPane.getChildren().add(this.usernameField);
//
//		// add password
//		Label passwordLabel = new Label("Password:");
//		this.passwordField = new TextField();
//		rightPane.getChildren().add(passwordLabel);
//		rightPane.getChildren().add(this.passwordField);
//
//		// add preferred name
//		Label preferredNameLabel = new Label("Preferred name:");
//		this.preferredNameField = new TextField();
//		rightPane.getChildren().add(preferredNameLabel);
//		rightPane.getChildren().add(this.preferredNameField);
//
//		// add age
//		Label ageLabel = new Label("Age:");
//		this.ageField = new TextField();
//		ageField.setTextFormatter(new TextFormatter<>(new NumberStringConverter()));
//		rightPane.getChildren().add(ageLabel);
//		rightPane.getChildren().add(this.ageField);
//
//		// add isManager
//		this.isManagerRadio = new RadioButton("Are you manager?");
//		rightPane.getChildren().add(this.isManagerRadio);
//		
//		this.isSeniorRadio = new RadioButton("Are you senior employee?");
//		rightPane.getChildren().add(this.isSeniorRadio);
		
		for (Leave l : leaves) {
			rightPane.getChildren().add(this.addRow(l));
		}

		// add buttons
		rightPane.getChildren().add(actionButtons());
		
		rightPane.prefWidthProperty().bind(panes.widthProperty().divide(4).multiply(3));

		panes.getChildren().add(leftPane);
		panes.getChildren().add(rightPane);
		
		return panes;
	}
	
	public HBox addRow(Leave l) {
		Employee u = l.getEmployee();
		Calendar d = l.getDate();
		HBox row = new HBox();
		row.setSpacing(10);
		row.setPadding(new Insets(10,10,10,10));
		
		Label nameLabel = new Label(u.getName());
		row.getChildren().add(nameLabel);
		
		Label eidLabel = new Label(Integer.toString(u.getEid()));
		row.getChildren().add(eidLabel);
		
		Label dateLabel = new Label (Converters.calendar2Str(d));
		row.getChildren().add(dateLabel);
		
		Label leaveType = new Label (l.getType());
		row.getChildren().add(leaveType);
		
		RadioButton ticktickRadio = new RadioButton("approve");
		row.getChildren().add(ticktickRadio);
		this.approved.add(ticktickRadio);
		
		return row;
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
	
	public EventPageHomePage getEventPageHomePage() {
		return eventPageHomePage;
	}
	
	public EventTakeLeave getEventTakeLeave() {
		return eventTakeLeave;
	}
	
	public Calendar getStartDate() {
		return Calendar.getInstance();
	}
	
	public Calendar getEndDate() {
		return Calendar.getInstance();
	}
	
	
}
