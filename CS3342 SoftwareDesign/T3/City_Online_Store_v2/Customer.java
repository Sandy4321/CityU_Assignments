   public class Customer
{
    private static Customer customer;
    private double total;
    private State state;
    
    /**
     * Constructor for objects of class Customer
     */
    public Customer()
    {
        state = new Typical();
    }
    
    public static Customer lookup()
    {
        return customer;
    }
    
    public int discount()
    {
        return state.discount();
    }
    
    public int deposit ()
    {
        return state.deposit();
    }
    
    public String type()
    {
        return state.type();
    }
    
    public void promote (double amount)
    {
        total += amount;
        if (total > 10000)
            state = new Golden();
        else if (total > 5000)
            state = new VIP();
    }
        
    


}
