package ui;

import java.util.ArrayList;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import main.Frontend;

public class App extends Application implements EventHandler<ActionEvent> {
	
	public static void start(String[] args) {
		try {
			launch(args);
		}catch(Exception e) {
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
	
	
	@Override
	public void start(Stage primaryStage) throws Exception {
		this.ps = primaryStage;
		primaryStage.setTitle("Leave System.");
		
		primaryStage.setScene(scene1());
		primaryStage.show();
		
	}

	@Override
	public void handle(ActionEvent event) {
		
		// Upon event this will be fired.
		if (event.getSource() == this.login) {
			Frontend fe = Frontend.getInstance();
			if(fe.authUser(username.getText(),password.getText())) {
				this.ps.setScene(scene2("Auth Success"));
			}else {
				this.ps.setScene(scene2("Auth Failure"));
			}
			this.ps.show();
		}else if(event.getSource() == this.signup) {
			this.ps.setScene(scene3());
		}else if(event.getSource() == this.backButton) {
			this.ps.setScene(scene1());
			this.ps.show();
		}else if(event.getSource() == this.backButton) {
			this.ps.setScene(scene1());
			this.ps.show();
		}else if (event.getSource() == this.signupReal) {
			Frontend fe = Frontend.getInstance();
			if(fe.dummy_insertUser(username.getText(),password.getText())) {
				this.ps.setScene(scene2("Account Created Success"));
			}else {
				this.ps.setScene(scene2("Account Created Failure"));
			}
			this.ps.show();
		}
		
		
	}
	
	public Scene scene1() {

		// Stage -> Scene -> Layout -> Buttons, blahblah.....
		
		// creating layout

		ArrayList<Node> nodes = new ArrayList();
		
//		button = new Button();
//		button.setText("Click me.");
//		button.setOnAction(this); // parameter is the class instance, can be other class instance.
//		nodes.add(button);
//		

//		
//		HBox hb = new HBox();
//		hb.getChildren().addAll(label1, textField);
//		hb.setSpacing(10);
//		nodes.add(hb);
		
		BorderPane border = new BorderPane();
		HBox headerBox = addHeader();
		border.setTop(headerBox);
		
		VBox contentBox = addContent();
		border.setCenter(contentBox);
		
		
		
		
		
//		addStackPane(hbox);     
		// Add stack to HBox in top region
//		nodes.add(border);
//
//	
//		StackPane layout = new StackPane();
//		for (Node node: nodes) {
//			
//			layout.getChildren().add(node);
//		}
		
		Scene scene = new Scene(border, 1080,720);
		return scene;
	}
	
	public Scene scene2(String authState) {

		// Stage -> Scene -> Layout -> Buttons, blahblah.....
		
		// creating layout

		ArrayList<Node> nodes = new ArrayList();
		
		
		
		VBox vbox = new VBox();
		vbox.setAlignment(Pos.CENTER);
		vbox.setSpacing(10);
		
		Text title = new Text(10, 50, authState);
	    title.setFont(new Font(20));
		vbox.getChildren().add(title);
		
		backButton = new Button();
		backButton.setText("Try Again");
		backButton.setOnAction(this); // parameter is the class instance, can be other class instance.
		vbox.getChildren().add(backButton);
//		title.setFill(Color.WHITE);
//		nodes.add(vBox);
//		

		
//		
//		HBox hb = new HBox();
//		hb.getChildren().addAll(label1, textField);
//		hb.setSpacing(10);
//		nodes.add(hb);
		
//		BorderPane border = new BorderPane();
//		HBox headerBox = addHeader();
//		border.setTop(headerBox);
//		
//		VBox contentBox = addContent();
//		border.setCenter(contentBox);
		
		
		
		
		
//		addStackPane(hbox);     
		// Add stack to HBox in top region
//		nodes.add(border);
//
//	
		StackPane layout = new StackPane();
//		for (Node node: nodes) {
//			
			layout.getChildren().add(vbox);
//		}
		
		Scene scene = new Scene(layout, 1080,720);
		return scene;
	}
	public Scene scene3() {

		// Stage -> Scene -> Layout -> Buttons, blahblah.....
		
		// creating layout

		ArrayList<Node> nodes = new ArrayList();
		
		
		
		VBox vbox = new VBox();
		vbox.setAlignment(Pos.CENTER);
		vbox.setSpacing(10);
		
		Label label1 = new Label("Username:");
	    TextField textField = new TextField();
	    vbox.getChildren().add(label1);
	    vbox.getChildren().add(textField);
	    username = textField;
	    
	    Label label2 = new Label("Password:");
	    TextField textField2 = new TextField();
	    vbox.getChildren().add(label2);
	    vbox.getChildren().add(textField2);
	    password = textField2;
	    
	    signupReal = new Button("Sign Up");
	    signupReal.setPrefSize(100, 20);
	    signupReal.setOnAction(this); // paramet
	    vbox.getChildren().add(signupReal);
	    
	    
//		title.setFill(Color.WHITE);
//		nodes.add(vBox);
//		

		
//		
//		HBox hb = new HBox();
//		hb.getChildren().addAll(label1, textField);
//		hb.setSpacing(10);
//		nodes.add(hb);
		
//		BorderPane border = new BorderPane();
//		HBox headerBox = addHeader();
//		border.setTop(headerBox);
//		
//		VBox contentBox = addContent();
//		border.setCenter(contentBox);
		
		
		
		
		
//		addStackPane(hbox);     
		// Add stack to HBox in top region
//		nodes.add(border);
//
//	
		StackPane layout = new StackPane();
//		for (Node node: nodes) {
//			
			layout.getChildren().add(vbox);
//		}
		
		Scene scene = new Scene(layout, 1080,720);
		return scene;
	}
	
	public HBox addHeader() {
	    HBox hbox = new HBox();
	    hbox.setPadding(new Insets(15, 12, 15, 12));
	    hbox.setSpacing(10);
	    hbox.setStyle("-fx-background-color: BLACK;");
	    hbox.setAlignment(Pos.CENTER);
	    
	    
	    Text title = new Text(10, 50, "CS3343 HR System");
	    title.setFont(new Font(20));
		title.setFill(Color.WHITE);
//		nodes.add(t);
	    
//		Label label1 = new Label("Username:");
		
//		label1.setStyle("-fx-text-fill:white");
//		TextField textField = new TextField ();

//	    Button buttonCurrent = new Button("Current");
//	    buttonCurrent.setPrefSize(100, 20);
//
//	    Button buttonProjected = new Button("Projected");
//	    buttonProjected.setPrefSize(100, 20);

	    hbox.getChildren().add(title);
//	    hbox.getChildren().add(textField);


	    return hbox;
	}
	
	public VBox addContent() {
		VBox vbox = new VBox();
		vbox.setAlignment(Pos.CENTER);

	    vbox.setSpacing(10);
		vbox.setMaxWidth(400)
		;
	    
//	    Rectangle rect = new Rectangle(400,400);
//	    rect.setFill(Color.GREEN);
//	    vbox.getChildren().add(rect);
	    
	    Label label1 = new Label("Username:");
	    TextField textField = new TextField();
	    vbox.getChildren().add(label1);
	    vbox.getChildren().add(textField);
	    username = textField;
	    
	    Label label2 = new Label("Password:");
	    TextField textField2 = new TextField();
	    vbox.getChildren().add(label2);
	    vbox.getChildren().add(textField2);
	    password = textField2;
	    
	    
	    
	    

	    HBox buttons = new HBox();
	    buttons.setAlignment(Pos.CENTER);
	    buttons.setSpacing(10);
	    
	    Button buttonLogin = new Button("Login");
	    buttonLogin.setPrefSize(100, 20);
	    buttons.getChildren().add(buttonLogin);

	    buttonLogin.setOnAction(this); // parameter is the class instance, can be other class instance.
	    this.login = buttonLogin;
	    
	    Button buttonSignUp = new Button("Sign Up");
	    buttonSignUp.setPrefSize(100, 20);
	    buttons.getChildren().add(buttonSignUp);
	    
	    buttonSignUp.setOnAction(this);
	    this.signup = buttonSignUp;
	    
	    vbox.getChildren().add(buttons);
	    
		return vbox;
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
