package events;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Node;
import ui.Presentation;

public abstract class EventBoardcaster implements EventHandler<ActionEvent> {
	protected Presentation p;
	protected final Node n;
	
	public EventBoardcaster(Node n) {
		this.n = n;
	}
	
	public void setPresentation(Presentation p) {
		this.p = p;
	}
	
	public void call() {
		this.handle(null);
	}
}
