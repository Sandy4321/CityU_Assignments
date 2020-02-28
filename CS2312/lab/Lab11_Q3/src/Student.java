import java.util.ArrayList;

public class Student {

	private String id;
	private ArrayList<Offering> studies;

	public Student(String id) {
		this.id=id;
		this.studies = new ArrayList<>();
	}

	public void takeCourse(Course course, String semID) {
		Offering tempO = course.getOffering(semID);
		this.studies.add(tempO);
		tempO.addStudent(this);
		
	}

	public boolean hasBeenClassmateOf(Student s2) {
		for(Offering o : studies) {
			if(s2.hasTaken(o)) {
				return true;
			}
		}
		return false;
	}

	private boolean hasTaken(Offering o) {
		for(Offering offering: studies) {
			if(o==offering) {
				return true;
			}
		}
		return false;
	}
	public String toString() {
		return this.id;
	}

}
