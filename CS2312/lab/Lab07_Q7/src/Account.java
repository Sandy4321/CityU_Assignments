
public abstract class Account{
	private String account_no;
	public Account(String ano) {
		account_no = ano;
	}
	public String getAccountNumber() {
		return this.account_no;
	}
	public abstract double getTotal();
	
	public String toString() 
	{
		return "Bank A/C Number: "+getAccountNumber();
	}
}