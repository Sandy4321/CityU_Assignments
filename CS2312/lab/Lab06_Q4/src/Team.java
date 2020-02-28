import java.util.*;
import java.io.*;

public class Team{
	
	//Instance data field
//	_________________________________________
	private ArrayList<Member> allMembers;
	
	//Constructor	
	public Team(String filepathname) throws FileNotFoundException
	{
		Scanner inFile = new Scanner(new File(filepathname));
		
		int tot = inFile.nextInt(); //Read from file: nextInt();
		inFile.nextLine(); //skip line break after the count: inFile.nextLine(); 
		allMembers = new ArrayList<Member>(); //Create the array: new Member[tot];

		for (int i = 0 ; i < tot ; i ++) //loop how many times?
		{
			String name = inFile.next(); //Read from file: .next();
			char roleType = inFile.next().charAt(0); //Read a string of one character and get that character: inFile.next().charAt(0);
			
			Role r;		
			if (roleType=='l')	r = new RLeader(); //create a RLeader role object: new RLeader();
			else if (roleType=='d') r = new RDisappeared();
			else /*roleType=='n'*/	r = new RNormalMember(); //create a RNormalMember role object: new RNormalMember();
			
			allMembers.add( new Member(name,r)); // Create a member object: new ____________;
		}
				
		inFile.close(); //close the file
	}
	
	//Return total count of members (simply allMembers.length)
	public int getMemberCount()
	{
		return allMembers.size();
	}
	
	public String getStringOfAllMembers()
	{
		String result="";
		for (Member m : allMembers) //loop for each member
				result+= m.getNameAndRole()+" ";// allMembers[i].getName()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}
	
	//Return a string of listing of all members
	public String getStringOfNormalMembers()
	{
		String result="";
		for (Member m : allMembers)
			if (m.getRole() instanceof RNormalMember)
				result+= m.getNameAndRole()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}

	//Display team contact messages
	public void printTeamContactMessages()
	{
		for (int i=0;i<allMembers.size();i++)
		{
			String name_i=allMembers.get(i).getName(); //e.g. "Helena"
			System.out.print("Dear " + name_i + ",  ");
			String teammates = allMembers.get(i).getRole().genTeamContactMsg(this); // allMembers[i].getRole().genTeamContactMsg(this);
			System.out.println(teammates); // teammates
		}
	}	
	public Member getLeader()
	{
		for (int i=0;i<allMembers.size();i++)
			if (allMembers.get(i).getRole() instanceof RLeader) //checking:  allMembers[i].getRole() instanceof RLeader
				return allMembers.get(i);
		return null; //not found
	}
	
	public Member findMember(String m) {
		for(int i = 0 ; i < allMembers.size() ; i++) {
			if (m.equals(allMembers.get(i).getName())) return allMembers.get(i);
		}
		return null;
	}
	public void changeLeader(String newLeaderName) {
		Member oldL = getLeader();
		oldL.setRole(new RNormalMember());
		// remove old first!!!
		Member newL = findMember(newLeaderName);
		newL.setRole(new RLeader());
	}

	public void requestNewLeader(Scanner s) {
		System.out.print("Enter new leader: ");
		String newLeader = s.next();
		changeLeader(newLeader);
		System.out.println("Result: " + getStringOfAllMembers());
	}	
	
}