package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;

public class EventPageHomePage extends EventBoardcaster {
	
	public EventPageHomePage(Node n) {
		super(n);
	}
	
	@Override
	public void handle(ActionEvent e) {
		this.p.goHomePage();
	}
	
}
