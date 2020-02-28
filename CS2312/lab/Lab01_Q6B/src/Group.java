public class Group {
	
	private Customer[] customers;
	
	public Group() {
		customers = new Customer[0];
	}
	
	public void add(Customer c) {
		Customer tempCustomers[] = new Customer[customers.length + 1];
		int i = 0;
		for ( i = 0 ; i < customers.length ; i ++){
			tempCustomers[i] = customers[i];
		}
		tempCustomers[i] = c;
		customers = tempCustomers;
	}
	
	public void spend(int value) {
		final int spendingForEachCustomer = value / customers.length;
		for (int i = 0 ; i < customers. length ; i++ ){
			customers[i].spend(spendingForEachCustomer);
		}
	}
}
