public class VIP implements State
{
    public int discount() { return 80; }

    public int deposit() { return 50; }
    
    public String type() {  return "VIP"; }
}
