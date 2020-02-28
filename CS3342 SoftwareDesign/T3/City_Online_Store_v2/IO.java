import java.io.*;
import java.util.Scanner; 


public class IO
{
 
    public void getInput(){
        Manager manager = new Manager();
        int n;
        double [] amount;
        Scanner io = new Scanner (System.in);
        
        n = readInteger(io);
        amount = new double[n];
        
        for (int i=0; i<n; i++)
            amount[i] = readInteger(io);
            
        for (int i=0; i<n; i++)
            manager.process (amount[i]);
            
    }
    
    public int readInteger(Scanner read)
    {
        try {
            return read.nextInt();
        } catch (Exception e ) { 
            return 0;
        } 
    }
    
    public static void main (String[] args){
        IO io = new IO();
        io.getInput();
    }
    
}
