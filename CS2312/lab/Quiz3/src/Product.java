
public class Product extends Tradable {

	private final int DISCOUNT = 10;
	
	public Product(String id, int price) {
		super(id,price);
	}

	@Override
	public int getDiscountPercent() {
		if (super.getPrice() > 50) return DISCOUNT;
		return 0;
	}

	@Override
	public int getEarning() {
		return super.getPrice()*10/100;
	}


}
