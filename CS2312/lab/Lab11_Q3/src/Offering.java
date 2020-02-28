import java.util.ArrayList;

public class Offering {

	private String semID;
	private ArrayList <Student> students;

	public Offering(String semID) {
		this.semID = semID;
		this.students = new ArrayList<>();
	}

	public String getSemID() {
		// TODO Auto-generated method stub
		return semID;
	}
	public void addStudent(Student s) {
		students.add(s);
	}

	public void listStudents() {
		System.out.print(semID +": ");
		for(Student s : students) {
			System.out.print(s+" ");
		}
		System.out.println();
			
	}

}
