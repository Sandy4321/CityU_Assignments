import java.util.List;

public class DropController extends Controller {
	

	public DropController(List<Course> list) {
		super(list);
	}

	@Override
	public void process(Course c) {
		getCourseList().remove(c);
	}
}