import java.util.*;
import java.io.*;

public class Main{
	
	//Add the method called findAccount
	public static Account findAccount(ArrayList<Account> arrA,String search) {
		for(Account a: arrA) {
			if(search.equals(a.getAccountNumber())) {
				return a;
			}
		}
		return null;
	}
	
	
	
	
	
	public static void main(String [] args) throws FileNotFoundException
	{	
		
		Scanner in = new Scanner(System.in);
		
		System.out.print("Please input the file pathname: ");
		String filepathname = in.nextLine();
		
		ArrayList<Account> acs = new ArrayList<>();
		
		Scanner infile = new Scanner(new File(filepathname));
		
		while(infile.hasNextLine()) {
			String[] s = infile.nextLine().split(" ");
			int firstIntOfString = (int)s[0].charAt(0) - 48;
			if(firstIntOfString <= 5) {
				acs.add(new SavingAccount(s[0],Double.parseDouble(s[1])));
			}else if(firstIntOfString <=8 ) {
				acs.add(new CreditCardAccount(s[0],Double.parseDouble(s[1]),Double.parseDouble(s[2])));
			}else {
				acs.add(new PowerAdvantageAccount(s[0], (SavingAccount)findAccount(acs,s[1]), (CreditCardAccount)findAccount(acs,s[2])));
			}
		}
		
		
		
		
		
		infile.close();
		System.out.print("\nInput an account number to search: ");
		
		Account res = findAccount(acs,in.next());
		
		if (res!=null)
			System.out.println("\n[Result]\n"+res);
		else
			System.out.println("\n[Result]\nThe account is not found.");
			
		in.close();
	}
}