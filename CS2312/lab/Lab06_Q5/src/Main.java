import java.util.*;
import java.io.*;

public class Main{

	public static void main(String [] args) throws FileNotFoundException
	{	
		Scanner in = new Scanner(System.in);
		
		System.out.print("Please input the file pathname of each team: ");
		String filepathname = in.nextLine();

		ArrayList<Team> teams;
		teams = new ArrayList<Team>(); //See Lab05 page 2.
		
		Scanner s = new Scanner(filepathname);//create the team: new ______________________;
		while(s.hasNext()) {
			teams.add(new Team(s.next()));
		}
		System.out.println("\nListing of teams:");
		for(int i = 0 ; i < teams.size();i++) {
			System.out.printf("[Team %d] %d members: %s\n",i+1,teams.get(i).getMemberCount(),teams.get(i).getStringOfAllMembers());
		}
		System.out.println();
		System.out.print("\nEnter a name for searching: ");
		String searchMember = in.next();
		boolean found = false;
		for (int i= 0;i<teams.size()&&!found;i++) {
			Member tempMember = teams.get(i).findMember(searchMember);
			if(tempMember!=null) {
				found =true;
				System.out.printf("Result: %s is %s in Team %d",searchMember,tempMember.getRoleDescription(),i+1);
			}
		}
		if (!found) {
			System.out.println("Result: Not found");
		}
		
//		System.out.printf(
//			"\nThere are %d members in the team: %s\n\n", 
//			t.getMemberCount(),t.getStringOfAllMembers()); //call Team methods to get the results: getMemberCount, getStringOfAllMembers
		
//		System.out.println("Messages for team contacts: ");
//		t.printTeamContactMessages(); //call Team method: printTeamContactMessages
		
//		t.requestNewLeader(in);
		
		in.close();
	}
}