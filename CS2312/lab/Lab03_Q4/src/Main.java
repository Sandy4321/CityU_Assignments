import java.util.*;
import java.io.*;

public class Main {

	// Your task:
	// Todo(1) the main() method --- see Main_GivenCode.txt
	public static void main(String[] args) throws FileNotFoundException {
		System.out.print("Please input the file pathname: ");
		Scanner in = new Scanner(System.in);
		String filepathname = in.nextLine();

		Student[] students; // Define an array of students: Student[] students;
		students = Student.createStudentListFromFile(filepathname); // Call the given static method in the Student class
																	// for reading from file:
																	// Student.createStudentListFromFile(filepathname);

		System.out.println("Total number of students: " + students.length);

		
		System.out.print("Enter the number of teams: ");

		int nTeams = in.nextInt();
		if (students.length % nTeams != 0) {
			System.out.println("Wrong input - It is not a factor of " + students.length + ".");
		} else {

			Team[] teams; // Define an array of teams: Team []
			teams = createTeams(students,nTeams);// Call the private method (one of the 3 methods in Main.java) to create the
											// teams for students: createTeams(students);

			// Print the grouping result:
			System.out.println("\nGrouping result: ");
			
			for (int i = 0 ; i < teams.length ; i++) {
				System.out.println(teams[i]);
			}
//			System.out.println(teams[0].toString());
//			System.out.println(teams[1].toString());
//			System.out.println(teams[2].toString());
//			System.out.println(teams[3].toString());
//			System.out.println(teams[4].toString());

			System.out.println("Enter "+teams.length+" task names (eg. \"Lab05 Lab06 Lab07 ..\"): ");
			String[] taskNames = new String[teams.length];
			for (int i = 0 ;i < teams.length ; i++) {
					taskNames[i] = in.next();
			}
			
			
			// Create the assignments
			Assignment[] assignments; // Define an array of assignments: Assignment[] assignments
			assignments = decideTasks(teams, in,taskNames);// Call the private method (one of the 3 methods in Main.java) to input
													// the tasks for each team: decideTasks(teams, in);
			
			
			
			// Display sorted listing by tasks:
			System.out.println("\nSorted listing by tasks: ");
			for (int i = 0; i < taskNames.length ; i++) {
				for (int j = 0; j < taskNames.length -i ; j++) {
					if (taskNames[i])
				}
			}
			
			Assignment.printTaskTeam("Lab05", assignments);
			Assignment.printTaskTeam("Lab06", assignments);
			Assignment.printTaskTeam("Lab07", assignments);
			Assignment.printTaskTeam("Lab08", assignments);
			Assignment.printTaskTeam("Lab09", assignments);

			in.close();
		}
	}

	// Todo(2) the createTeams() method --- see Main_GivenCode.txt
	// Create the teams from the students array: students[0..5] go to team A,
	// students[6..11] go to team B, etc..
	private static Team[] createTeams(Student[] students, int nTeams) {
		Team[] result; // Define an array of teams to store the result: Team[] result;
		result = new Team[nTeams]; // Create the array: new Team[5];

		int increment = 0;
		
		for(int i = 0 ; i < nTeams ; i++) {
			result[i] = new Team("Team "+(char)('A'+i) ,Arrays.copyOfRange(students, increment, increment+=students.length/nTeams));
		}
		
//		// Create the 5 teams
//		result[0] = new Team("Team A", Arrays.copyOfRange(students, incrementBy6, incrementBy6 += 6)); // give team name
//																										// and array of
//																										// 6 students:
//																										// "Team A",
//																										// Arrays.copyOfRange(students,
//																										// 0,6)
//		result[1] = new Team("Team B", Arrays.copyOfRange(students, incrementBy6, incrementBy6 += 6)); // Create the
//																										// second team :
//																										// new
//																										// Team("Team
//																										// B",
//																										// Arrays.copyOfRange(students,
//																										// 6,12));
//		result[2] = new Team("Team C", Arrays.copyOfRange(students, incrementBy6, incrementBy6 += 6));
//		result[3] = new Team("Team D", Arrays.copyOfRange(students, incrementBy6, incrementBy6 += 6));
//		result[4] = new Team("Team E", Arrays.copyOfRange(students, incrementBy6, incrementBy6 += 6));
		return result; // Return the result: return result;
	}

	// Todo(3) the decideTasks() method --- see Main_GivenCode.txt
	// assignment of lab tasks to teams based on user input
	private static Assignment[] decideTasks(Team[] teams, Scanner in,String[] taskNames) {
		
		
		
		
		Assignment[] assignments; // Define an array of assignments to store the result: Assignment[] assignments;
		assignments = new Assignment[teams.length]; // Create the array: new Assignment[5];

		System.out.print("\nEnter tasks for the teams ("+taskNames[0]);
		for ( int i = 0 ; i < taskNames.length ; i++) {
			System.out.print(","+taskNames[i]);
		}
		
		System.out.println("): ");
		for (int i = 0; i < teams.length; i++) {
			System.out.print(teams[i].getName() + ": "); // Prompt for a team: teams[i].getName()
			String taskName = in.next(); // Get user input of the task name from keyboard: in.next();
			assignments[i] = new Assignment(teams[i], new Task(taskName)); // Create the assignment for: teams[i], new
																			// Task(taskName)
		}
		return assignments; // Return the result: return assignments;
	}
}