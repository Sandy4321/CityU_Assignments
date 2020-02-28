package events;

import javafx.event.ActionEvent;
import javafx.scene.Node;
import ui.PaneLogin;

public class EventLogin extends EventBoardcaster {
	public EventLogin(Node n) {
		super(n);
	}
	@Override
	public void handle(ActionEvent e) {
		PaneLogin n = (PaneLogin) this.n;
		if (!(n.getUsername().isEmpty() || n.getPassword().isEmpty())) {
			this.p.login( n.getUsername() , n.getPassword() );
		}
	}
}
