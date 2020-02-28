package ui;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;

public class Components {

	public static HBox generate_header() {
		HBox hbox = new HBox();
		hbox.setPadding(new Insets(15, 12, 15, 12));
		hbox.setSpacing(10);
		hbox.setStyle("-fx-background-color: BLACK;");
		hbox.setAlignment(Pos.CENTER);

		Text title = new Text(10, 50, "CS3343 HR System");
		title.setFont(new Font(20));
		title.setFill(Color.WHITE);
		hbox.getChildren().add(title);

		return hbox;
	}
}
