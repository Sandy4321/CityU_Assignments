import java.util.List;

public abstract class Controller {
	private List<Course> courseList ;
	
	public Controller(List<Course> courseList) {
		this.courseList = courseList;
	}
	
	
	public abstract void process(Course c);
	
	public void printCourses() {
		System.out.print("Course List: ");
		for(Course c : courseList) {
			System.out.printf("[%s] ",c);
		}
		System.out.println();
	}
	protected List<Course> getCourseList(){
		return courseList;
	}
	
}
