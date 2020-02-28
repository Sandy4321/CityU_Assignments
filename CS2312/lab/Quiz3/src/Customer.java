class Customer {
	private String name;

	public Customer(String name) {
		this.name = name;
	}

	public void order(IConsumable cons, Shop s) {
		System.out.println(name + " orders " + cons + " from " + s + ", price is " + cons.getPrice()
				+ ", discount percentage is " + cons.getDiscountPercent());
		s.processOrder(this, cons);
	}
}