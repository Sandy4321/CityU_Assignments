public class Golden implements State
{
    // "Singleton Pattern" 
    private static Golden this_instance = new Golden();    
    // "Private" Constructor" to Prevent direction object creation 
    private Golden () {} 
    
    public static Golden getInstance() { return this_instance; }
    
    public int discount() { return 50; }

    public int deposit() { return 0; }
    
    public String type() {  return "Golden"; }
}
