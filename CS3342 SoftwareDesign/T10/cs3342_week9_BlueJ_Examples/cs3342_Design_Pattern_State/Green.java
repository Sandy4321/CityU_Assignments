public class Green implements Membership
{
    public int discount() {
        return 100;
    }
    public int deposit() {
        return 100;
    }
    public String type() {
        return this.getClass().getName();
    }
}

