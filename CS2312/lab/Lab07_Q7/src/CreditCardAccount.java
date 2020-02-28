/*
Add the class called CreditCardAccount 
It should extend the superclass: Account 

Given code for strings:
 return "Credit Card A/C Number: "+____________+
				" Balance: $"+String.format("%.2f",____________)+
				" Credit limit: $"+String.format("%.2f",____________);

*/

public class CreditCardAccount extends Account{
	
	private double balance,creditLimit;
	
	
	public CreditCardAccount(String ano,double bal, double climit) {
		super(ano);
		this.balance = bal;
		this.creditLimit = climit;
	}

	public String toString() {
		return "Credit Card A/C Number: "+super.getAccountNumber()+
				" Balance: $"+String.format("%.2f",this.balance)+
				" Credit limit: $"+String.format("%.2f",this.creditLimit);
	}

	@Override
	public double getTotal() {
		return this.balance;
	}
}