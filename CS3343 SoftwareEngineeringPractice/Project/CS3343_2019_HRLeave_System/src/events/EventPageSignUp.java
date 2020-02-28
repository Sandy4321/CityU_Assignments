package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;

public class EventPageSignUp extends EventBoardcaster {
	public EventPageSignUp(Node n) {
		super(n);
	}
	@Override
	public void handle(ActionEvent e) {
		this.p.goSignUpPage();
	}
}
