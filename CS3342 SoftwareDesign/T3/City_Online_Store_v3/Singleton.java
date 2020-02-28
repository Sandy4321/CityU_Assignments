// This implements an example Singleton Pattern
public class Singleton
{
    private static final Singleton instance = new Singleton(); 
    
    private Singleton(){
    }
    
    public static Singleton getInstance(){
        return instance;
    }

    public void printString(){
        System.out.println ("I am Singleton!");
    }
    
    public static void main(String[] args){
        Singleton.getInstance().printString(); 
    }
    
}
