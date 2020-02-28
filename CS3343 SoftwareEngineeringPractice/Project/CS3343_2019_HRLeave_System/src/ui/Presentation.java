package ui;

import java.util.Calendar;

import events.EventLogout;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import main.Frontend;
import user.Employee;

public class Presentation extends Application {

	private Frontend fe;

	public static void start(String[] args) {
		try {
			launch(args);
		} catch (Exception e) {
			System.out.println(e);
		}

	}

	private Button backButton;
	private Button login;
	private Button signup;
	private Button signupReal;

	private TextField username;
	private TextField password;
	private Stage ps;

	private EventLogout eventLogout = new EventLogout(null);

	@Override
	public void start(Stage primaryStage) throws Exception {

		this.fe = Frontend.getInstance();

		this.ps = primaryStage;
		primaryStage.setTitle("CS3343 HR Leave System.");

		primaryStage.setWidth(1080);
		primaryStage.setHeight(720);
		this.goLoginPage();
	}

	public Scene createScene(Node centerNode) {
		return this.createScene(centerNode, null);
	}

	public Scene createScene(Node centerNode, Node footerNode) {
		BorderPane borderPane = new BorderPane();

		HBox headerBox = Components.generate_header();
		if (fe.loggedIn()) {
			addStackPane(headerBox);
		}
		borderPane.setTop(headerBox);

		borderPane.setCenter(centerNode);

		if (footerNode != null) {
			borderPane.setBottom(footerNode);
		}

		return new Scene(borderPane);
	}

	public void goSignUpPage() {
		PaneSignUp p = new PaneSignUp();
		p.getEventSignUp().setPresentation(this);
		p.getEventPageLogin().setPresentation(this);
		this.ps.setScene(createScene(p));
		this.ps.show();
	}

	public void goLoginPage() {
		PaneLogin p = new PaneLogin();
		p.getEventLogin().setPresentation(this);
		p.getEventPageSignUp().setPresentation(this);
		this.ps.setScene(createScene(p));
		this.ps.show();
	}

	public void goHomePage() {
		PaneHomePage p = new PaneHomePage(this.fe.getCurrUser(), this.fe.getUserOnLeaveToday());
		p.getEventPageTakeLeave().setPresentation(this);
		p.getEventPageManageLeave().setPresentation(this);
		this.ps.setScene(createScene(p));
		this.ps.show();
	}

	public void goTakeLeavePage() {
		PaneTakeLeave p = new PaneTakeLeave();
		p.getEventPageHomePage().setPresentation(this);
		p.getEventTakeLeave().setPresentation(this);
		this.ps.setScene(createScene(p));
		this.ps.show();
	}

	public void goManageLeavePage() {
		PaneManageLeave p = new PaneManageLeave(
			this.fe.getLeaves()
		);
		p.getEventPageHomePage().setPresentation(this);
		p.getEventTakeLeave().setPresentation(this);
		this.ps.setScene(createScene(p));
		this.ps.show();
	}

	public void login(String username, String password) {
		if (fe.authenticate_login_user(username, password)) {
			this.goHomePage();
		} else {
			alertMessage("Failed.", "Sign in failure.");
		}
	}

	public void signUp(String username, String password, String preferredName, int age, boolean isManager,
			boolean isSenior) {
		if (fe.insertUser(username, password, preferredName, age, isManager, isSenior)) {
			alertMessage("Success.", "Account Created Success");
			this.goLoginPage();
		} else {
			alertMessage("Failed.", "Account Created Failure");
		}
	}

	public void alertMessage(String title, String message) {
		Alert alert = new Alert(AlertType.INFORMATION);
		alert.setTitle("Information Dialog");
		alert.setHeaderText(title);
		alert.setContentText(message);

		alert.showAndWait();
	}

	public Node generate_header() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10);
		hbox.setStyle("-fx-background-color: BLACK;");
		hbox.setAlignment(Pos.CENTER);

		Text title = new Text(10, 50, "CS3343 HR System");
		title.setFont(new Font(20));
		title.setFill(Color.WHITE);
		hbox.getChildren().add(title);

		addStackPane(hbox);

		return hbox;
	}

	public void addStackPane(HBox hb) {
		StackPane stack = new StackPane();

		Button logoutButton = new Button("Logout");
		logoutButton.setOnAction(this.eventLogout);
		this.eventLogout.setPresentation(this);
		stack.getChildren().add(logoutButton);
		stack.setAlignment(Pos.CENTER_RIGHT); // Right-justify nodes in stack
		StackPane.setMargin(logoutButton, new Insets(0, 10, 0, 0)); // Center "?"

		hb.getChildren().add(stack); // Add to HBox from Example 1-2
		HBox.setHgrow(stack, Priority.ALWAYS); // Give stack any extra space
	}

	public void logout() {
		this.fe.logout();
		this.goLoginPage();
	}

	public void takeLeave(Calendar startDate, Calendar endDate,String leaveType) {
		
		Employee x = ((Employee) this.fe.getCurrUser());
		
		int leaveTypeInt = 0;
		switch(leaveType) {
		case "annual":
			leaveTypeInt = 2;
			break;
		case "sick":
			leaveTypeInt = 1;
			break;
		case "no pay":
			leaveTypeInt = 3;
			break;
		default:
			return;
		}
		
		if(this.fe.insertLeaves(x.applyLeave(leaveTypeInt, startDate, endDate),leaveType)) {
			this.alertMessage("Success", "Leaves created");
		}else {
			this.alertMessage("Failed", "Leaves failed to create.");
		}
	}

//	public void addStackPane(HBox hb) {
//	    StackPane stack = new StackPane();
//	    Rectangle helpIcon = new Rectangle(30.0, 25.0);
//	    helpIcon.setFill(new LinearGradient(0,0,0,1, true, CycleMethod.NO_CYCLE,
//	        new Stop[]{
//	        new Stop(0,Color.web("#4977A3")),
//	        new Stop(0.5, Color.web("#B0C6DA")),
//	        new Stop(1,Color.web("#9CB6CF")),}));
//	    helpIcon.setStroke(Color.web("#D0E6FA"));
//	    helpIcon.setArcHeight(3.5);

//	    helpIcon.setArcWidth(3.5);
//
//	    Text helpText = new Text("?");
//	    helpText.setFont(Font.font("Verdana", FontWeight.BOLD, 18));
//	    helpText.setFill(Color.WHITE);
//	    helpText.setStroke(Color.web("#7080A0")); 
//
//	    stack.getChildren().addAll(helpIcon, helpText);
//	    stack.setAlignment(Pos.CENTER_RIGHT);     // Right-justify nodes in stack
//	    StackPane.setMargin(helpText, new Insets(0, 10, 0, 0)); // Center "?"
//
//	    hb.getChildren().add(stack);            // Add to HBox from Example 1-2
//	    HBox.setHgrow(stack, Priority.ALWAYS);    // Give stack any extra space
//	}

}

//class ScreenController {
//    private HashMap<String, Pane> screenMap = new HashMap<>();
//    private Scene main;
//
//    public ScreenController(Scene main) {
//        this.main = main;
//    }
//
//    protected void addScreen(String name, Pane pane){
//         screenMap.put(name, pane);
//    }
//
//    protected void removeScreen(String name){
//        screenMap.remove(name);
//    }
//
//    protected void activate(String name){
//        main.setRoot( screenMap.get(name) );
//    }
//}
