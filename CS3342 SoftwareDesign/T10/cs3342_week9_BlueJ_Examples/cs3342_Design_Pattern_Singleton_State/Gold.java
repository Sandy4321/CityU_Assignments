public class Gold implements Membership
{
    private static final Membership instance = new Gold();
    private Gold () {}
    public static Membership getInstance() {
        return instance;
    }
    
    public int discount() {
        return 50;
    }
    public int deposit() {
        return 0;
    }
    public String type() {
        return this.getClass().getName();
    }
}

