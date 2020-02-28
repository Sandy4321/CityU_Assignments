package ui;

import java.util.Calendar;

import events.EventPageHomePage;
import events.EventTakeLeave;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.TextFormatter;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.util.converter.NumberStringConverter;
import util.Converters;

public class PaneTakeLeave extends VBox {

	private TextField leaveTypeField;
	private TextField startDateField;
	private TextField endDateField;

	private EventPageHomePage eventPageHomePage = new EventPageHomePage(this);
	private EventTakeLeave eventTakeLeave = new EventTakeLeave(this);

	public PaneTakeLeave() {
		this.setAlignment(Pos.TOP_CENTER);
		this.setSpacing(10);
		this.setMaxWidth(1000);
		
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
		
		Label leaveTypeLabel = new Label("Type (annual/sick/no pay):");
		this.leaveTypeField = new TextField();
		rightPane.getChildren().add(leaveTypeLabel );
		rightPane.getChildren().add(this.leaveTypeField);

		// add password
		Label startDateLabel = new Label("Start Date (YYYY-mm-dd):");
		this.startDateField = new TextField();
		rightPane.getChildren().add(startDateLabel);
		rightPane.getChildren().add(this.startDateField);

		// add preferred name
		Label endDateLabel = new Label("End Date (YYYY-mm-dd):");
		this.endDateField = new TextField();
		rightPane.getChildren().add(endDateLabel);
		rightPane.getChildren().add(this.endDateField);


		// add buttons
		rightPane.getChildren().add(actionButtons());
		
		rightPane.prefWidthProperty().bind(panes.widthProperty().divide(4).multiply(3));

		panes.getChildren().add(leftPane);
		panes.getChildren().add(rightPane);
		
		return panes;
	}

	public String getLeaveType() {
		return leaveTypeField.getText();
	}
	
	public EventPageHomePage getEventPageHomePage() {
		return eventPageHomePage;
	}
	
	public EventTakeLeave getEventTakeLeave() {
		return eventTakeLeave;
	}
	
	public Calendar getStartDate() {
		return Converters.str2Calendar(this.startDateField.getText());
	}
	
	public Calendar getEndDate() {
		return Converters.str2Calendar(this.endDateField.getText());
	}
	
	
}
