import java.util.List;

public class AddController extends Controller {
	

	public AddController(List<Course> list) {
		super(list);
	}

	
	
	@Override
	public void process(Course c) {	
		List<Course> tempCourse = getCourseList();
		if (tempCourse.contains(c)) 
			return ;
		
		for(Course course: c.getPreRequisites()) {
			process(course);
		}
		tempCourse.add(c);
	}
}