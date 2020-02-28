import java.util.*;
import java.io.*;

public class Team{
	
	//Instance data field
//	_________________________________________
	private Member[] allMembers;
	
	//Constructor	
	public Team(String filepathname) throws FileNotFoundException
	{
		Scanner inFile = new Scanner(new File(filepathname));
		
		int tot = inFile.nextInt(); //Read from file: nextInt();
		inFile.nextLine(); //skip line break after the count: inFile.nextLine(); 
		allMembers = new Member[tot]; //Create the array: new Member[tot];

		for (int i = 0 ; i < tot ; i ++) //loop how many times?
		{
			String name = inFile.next(); //Read from file: .next();
			char roleType = inFile.next().charAt(0); //Read a string of one character and get that character: inFile.next().charAt(0);
			
			Role r;		
			if (roleType=='l')	r = new RLeader(); //create a RLeader role object: new RLeader();
			else if (roleType=='d') r = new RDisappeared();
			else /*roleType=='n'*/	r = new RNormalMember(); //create a RNormalMember role object: new RNormalMember();
			
			allMembers[i] = new Member(name,r); // Create a member object: new ____________;
		}
				
		inFile.close(); //close the file
	}
	
	//Return total count of members (simply allMembers.length)
	public int getMemberCount()
	{
		return allMembers.length;
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
		for (int i=0;i<allMembers.length;i++)
			if (allMembers[i].getRole() instanceof RNormalMember)
				result+= allMembers[i].getNameAndRole()+" ";
		result=result.trim(); //.trim() is for removing leading and trailing spaces 
		return result;
	}

	//Display team contact messages
	public void printTeamContactMessages()
	{
		for (int i=0;i<allMembers.length;i++)
		{
			String name_i=allMembers[i].getName(); //e.g. "Helena"
			System.out.print("Dear " + name_i + ",  ");
			String teammates = allMembers[i].getRole().genTeamContactMsg(this); // allMembers[i].getRole().genTeamContactMsg(this);
			System.out.println(teammates); // teammates
		}
	}	
	public Member getLeader()
	{
		for (int i=0;i<allMembers.length;i++)
			if (allMembers[i].getRole() instanceof RLeader) //checking:  allMembers[i].getRole() instanceof RLeader
				return allMembers[i];
		return null; //not found
	}	
	
}