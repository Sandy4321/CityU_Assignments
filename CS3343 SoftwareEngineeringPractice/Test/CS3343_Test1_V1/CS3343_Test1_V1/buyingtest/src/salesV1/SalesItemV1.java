package salesV1;

public class SalesItemV1 {
    private BuyerV1 buyer;

    public SalesItemV1(BuyerV1 buyer) {
        this.buyer = buyer;
    }

    public double getDiscountRate(CategoryV1 item_cat, int item_quan) {
        double rate = 1.00;

        if (item_quan < 1) {
            return -1.00;
        }
        
        rate = item_cat.getRate(item_quan);
       

        if (buyer.isBirthdayThisWeek()) {
            if (item_quan > 5) { // This statement is labeled as T1
                rate = 0.50 * rate; 
            } else {
                rate = 0.85 * rate;
            }
        }

        return rate;
    }

}
