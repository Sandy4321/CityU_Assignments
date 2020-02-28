package salesV1;

public enum CategoryV1 {
	BOOK,
	FOOD,
	BEVERAGE,
	OTHER;

	public double getRate(int item_quan) {
		double rate;
		if (this == CategoryV1.BOOK) {
			rate = 0.90;
		} else if (this == CategoryV1.FOOD) {
			if (item_quan > 10) {
				rate = 0.90;
			} else if (item_quan > 3) {
				rate = 0.95; // This statement is labeled as L1
			} else {
				rate = 1.0;
			}
		} else if (this == CategoryV1.BEVERAGE) {
			if (item_quan > 6) {
				rate = 0.85; // This statement is labeled as L2
			} else {
				rate = 0.95;
			}
		} else {
			rate = 1.00;
		}
		return rate;
	}
}
