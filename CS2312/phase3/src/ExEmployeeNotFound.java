
public class ExEmployeeNotFound extends ExEmployee {

	private static final long serialVersionUID = 1L;

	public ExEmployeeNotFound() {
		super("Employee not found!");
	}

	public ExEmployeeNotFound(Employee e) {
		super("Employee not found. Name : " + e.getName());
	}

	public ExEmployeeNotFound(String eMsg) {
		super(eMsg);
	}
}
