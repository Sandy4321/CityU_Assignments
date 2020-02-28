public class Silver implements Membership
{
    private static final Membership instance = new Silver();
    private Silver () {}
    public static Membership getInstance() {
        return instance;
    }
    
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