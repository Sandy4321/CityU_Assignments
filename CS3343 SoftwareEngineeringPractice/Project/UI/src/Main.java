
import javafx.


public class Main extends Frame {
	
	Main(){
		Button b = new Button("b");
		b.setBounds(50,50,50,50);
		setTitle("b");
		add(b);
		setSize(200,400);
		setLayout(new FlowLayout());
		setVisible(true);
	}
	
	public static void main(String[] args) {
		System.out.println("Hello");
		Main m = new Main();
	}
}
