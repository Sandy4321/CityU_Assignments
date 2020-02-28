
public class Shop {

	private String name;
	private Tradable[] tradables;
	public Shop(String name, Tradable[] tradables) {
	this.name=name;
	this.tradables = tradables;
	}
	
	public String toString() {
		return name;
	}
	
	public void processOrder(Customer customer, IConsumable cons) {
		if(cons instanceof Tradable ) {
			for(Tradable t : tradables) {
				if(t == cons) {
					System.out.println("Traded: "+t +", Profit: "+t.getEarning());
					return;
				}
			}
			System.out.println("Not provided!");
		}
	}

}
