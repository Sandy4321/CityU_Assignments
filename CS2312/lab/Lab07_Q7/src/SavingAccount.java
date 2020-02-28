
public class SavingAccount extends Account{
	private double balance;
	public SavingAccount(String ano,double balance) {
		super(ano);
		this.balance = balance;
	}
	public String toString() {
		return "Savings A/C Number: "+super.getAccountNumber()+
				" Balance: $"+String.format("%.2f",this.balance
						);
	}
	
	

	public double getTotal() {
		return this.balance;
	}
}
/*
Add the class called SavingsAccount 
It should extend the superclass: Account 

Given code for strings:
 return "Savings A/C Number: "+_________________+
				" Balance: $"+String.format("%.2f",______________);

*/
