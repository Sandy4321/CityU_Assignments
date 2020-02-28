public class Green implements Membership
{
    // Singleton Instance 
    private static final Membership instance = new Green();
    
    // "private" constructor to preventing creating a new object
    private Green () {}
    
    // static function to return the only singleton object created for runtime
    public static Membership getInstance() {
        return instance;
    }
    
    // original implementations/logics 
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

