package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;
import ui.PaneTakeLeave;

public class EventPageTakeLeave extends EventBoardcaster {
	public EventPageTakeLeave(Node n) {
		super(n);
	}
	@Override
	public void handle(ActionEvent e) {
		this.p.goTakeLeavePage();
	}
}
