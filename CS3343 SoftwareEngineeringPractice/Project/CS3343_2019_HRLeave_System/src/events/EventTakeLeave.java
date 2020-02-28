package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;
import ui.PaneTakeLeave;

public class EventTakeLeave extends EventBoardcaster {

	public EventTakeLeave(Node n) {
		super(n);
	}

	@Override
	public void handle(ActionEvent event) {
		PaneTakeLeave n = (PaneTakeLeave) this.n;
		this.p.takeLeave(n.getStartDate(),n.getEndDate(),n.getLeaveType());
	}

}
