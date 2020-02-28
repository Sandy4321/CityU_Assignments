public class Silver implements Membership
{
    public int discount() {
        return 80;
    }
    public int deposit() {
        return 50;
    }
    public String type() {
        return this.getClass().getName();
    }
}