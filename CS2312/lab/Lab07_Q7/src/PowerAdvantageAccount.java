
public class PowerAdvantageAccount extends Account {

	private SavingAccount savingAcc;
	private CreditCardAccount creditAcc;
	
	public PowerAdvantageAccount(String ano,SavingAccount savingAcc, CreditCardAccount creditAcc) {
		super(ano);
		this.savingAcc = savingAcc;
		this.creditAcc = creditAcc;
		
	}
	public double getTotal() {
		return savingAcc.getTotal() - creditAcc.getTotal();
	}
	public String toString() {
		 return "Power Advantage A/C Number: "+super.getAccountNumber()+" Balance: $"+String.format("%.2f", getTotal())+
					"\n 1."+savingAcc+
					"\n 2."+creditAcc;

	}

}