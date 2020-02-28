package ui;

import java.util.ArrayList;

import events.EventPageManageLeave;
import events.EventPageTakeLeave;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import user.User;

public class PaneHomePage extends VBox {

	private TextField usernameField;
	private TextField passwordField;
	private TextField preferredNameField;
	private TextField ageField;
	private RadioButton isManagerRadio;
	
	private ArrayList<String> leaveUser;
	
	private boolean isManager;
	
	private Button takeLeaveButton;
	 private Button manageLeaveButton;
	// private Button queryLeaveButton;

	private EventPageTakeLeave eventPageTakeLeave = new EventPageTakeLeave(this);
	private EventPageManageLeave eventPageManageLeave = new EventPageManageLeave(this);

	public PaneHomePage(
		User user,
		ArrayList<String> leaveUser
//		Leave[] userLeave
	) {
		this.setAlignment(Pos.TOP_CENTER);
		this.setSpacing(10);
		this.setMaxWidth(1000);
		
		this.isManager = user.isManager();
		this.leaveUser = leaveUser;
		
		this.getChildren().add(add2Pane());

		// add buttons		
		// this.getChildren().add(actionButtons());
	}
	
	
	public HBox add2Pane() {
		HBox panes = new HBox();
		panes.setSpacing(10);
		
		// buttons
		VBox leftPane = new VBox();
		leftPane.setSpacing(10);
		leftPane.setPadding(new Insets(10,10,10,10));
		
		if (!this.isManager) {
			this.takeLeaveButton = new Button("Take Leave");
			this.takeLeaveButton.setOnAction(this.eventPageTakeLeave);
			leftPane.getChildren().add(this.takeLeaveButton);	
		}else {
			this.manageLeaveButton = new Button("Manager Leave");
			this.manageLeaveButton.setOnAction(this.eventPageManageLeave);
			leftPane.getChildren().add(this.manageLeaveButton);	
		}
		
		leftPane.prefWidthProperty().bind(panes.widthProperty().divide(4));

		VBox rightPane = new VBox();
		rightPane.setSpacing(10);
		
		rightPane.setPadding(new Insets(10,10,10,10));
		
		for (String name: this.leaveUser) {
			Label nameLabel = new Label(name);
			rightPane.getChildren().add(nameLabel);
		}
		
		rightPane.prefWidthProperty().bind(panes.widthProperty().divide(4).multiply(3));

		panes.getChildren().add(leftPane);
		panes.getChildren().add(rightPane);
		
		return panes;
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
		if (ageField.getText().isEmpty()) {
			return 0;
		}else {
			return Integer.parseInt(ageField.getText());
		}
	}
	
	public boolean getIsManager() {
		return isManagerRadio.isSelected();
	}
	
	
	public EventPageTakeLeave getEventPageTakeLeave() {
		return eventPageTakeLeave;
	}
	
	public EventPageManageLeave getEventPageManageLeave() {
		return eventPageManageLeave;
	}
	
	
}
