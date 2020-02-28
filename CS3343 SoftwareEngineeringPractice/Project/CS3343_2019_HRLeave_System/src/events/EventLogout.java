package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;

public class EventLogout extends EventBoardcaster {

	public EventLogout(Node n) {
		super(n);
	}

	@Override
	public void handle(ActionEvent event) {
		this.p.logout();
	}

}
