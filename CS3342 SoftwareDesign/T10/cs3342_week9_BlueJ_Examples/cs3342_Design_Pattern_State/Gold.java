public class Gold implements Membership
{
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

