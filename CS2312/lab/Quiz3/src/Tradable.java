
public abstract class Tradable implements IConsumable {

	private String id;
	private int price;

	public Tradable(String id, int price) {
		this.id = id;
		this.price = price;
	}

	public String toString() {
		// TODO Auto-generated method stub
		return id;
	}
	
	@Override
	public int getPrice() {
		return this.price;
	}

	public abstract int getEarning(); 

}
