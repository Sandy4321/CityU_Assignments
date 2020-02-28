package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;

public class EventPageLogin extends EventBoardcaster {
	public EventPageLogin(Node n) {
		super(n);
	}
	@Override
	public void handle(ActionEvent e) {
		this.p.goLoginPage();
	}
}
