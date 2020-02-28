public class VIP implements State
{
    // "Singleton Pattern" 
    private static VIP this_instance = new VIP();    
    // "Private" Constructor" to Prevent direction object creation 
    private VIP () {} 
    
    public static VIP getInstance() { return this_instance; }
    
    
    public int discount() { return 80; }

    public int deposit() { return 50; }
    
    public String type() {  return "VIP"; }
}
