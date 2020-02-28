
public class Customer {
	
	private int totalMoney;
	
	public Customer(int money) {
		totalMoney = money;
	}
	
	public int getAmount() {
		return totalMoney;
	}
	
	public void set(int money) {
		totalMoney = money;
	}
	
	public void spend(int value) {
		totalMoney -= value;
	}
}
