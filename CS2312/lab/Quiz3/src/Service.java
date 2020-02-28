
public class Service extends Tradable{

	private final int DISCOUNT = 20;

	
	public Service(String id, int price) {
		super(id,price);
		
		
	}

	@Override
	public int getDiscountPercent() {
		if (super.getPrice() > 100) return DISCOUNT;
		return 0;
	}

	@Override
	public int getEarning() {
		return super.getPrice()*30/100;
	}


}
