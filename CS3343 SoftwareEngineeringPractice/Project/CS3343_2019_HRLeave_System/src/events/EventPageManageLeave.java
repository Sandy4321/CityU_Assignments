package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;

public class EventPageManageLeave extends EventBoardcaster {
	public EventPageManageLeave(Node n) {
		super(n);
	}
	@Override
	public void handle(ActionEvent e) {
		this.p.goManageLeavePage();
	}
}
