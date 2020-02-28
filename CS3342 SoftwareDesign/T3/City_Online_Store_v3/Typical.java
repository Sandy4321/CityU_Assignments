public class Typical implements State
{
    // "Singleton Pattern" 
    private static Typical this_instance = new Typical();    
    // "Private" Constructor" to Prevent direction object creation 
    private Typical () {} 
    
    public static Typical getInstance() { return this_instance; }
    
    public int discount() { return 100; }

    public int deposit() { return 100; }
    
    public String type() {  return "Typical"; }
}
