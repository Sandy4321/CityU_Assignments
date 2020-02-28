package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;
import ui.PaneSignUp;

public class EventSignUp extends EventBoardcaster {

	public EventSignUp(Node n) {
		super(n);
	}

	@Override
	public void handle(ActionEvent e) {
		PaneSignUp n = (PaneSignUp) this.n;
		this.p.signUp(n.getUsername(), n.getPassword(), n.getPreferredName(), n.getAge(), n.getIsManager(), n.getIsSenior());
	}
}
