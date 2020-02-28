import java.util.Scanner; 

public class Procedural
{
    
    public static void main (String[] args){
        // 1. Setup and get inputs
        Scanner cin = new Scanner (System.in);
        int n;
        n = cin.nextInt();
        
        double [] amount = new double [n];
        for (int i=0; i<n; i++)
            amount[i] = cin.nextInt();
    
        // 2. Process input and display output
	    // 2.1 Setup Customer's initial state
        double total = 0;
        String state = "Typical";
        
        // 2.2 Process each transaction
        for (int i=0; i<n; i++) {
            // 2.2.1. Setup discount
            int discount = 100;
            if (state == "Typical")
                discount = 100;
            else if (state == "VIP")
                discount = 80;
            else if (state == "Golden")
                discount = 50;
            double final_price = amount[i] * discount / 100;
            
            // 2.2.2. Setup deposit to be paid
            int depositRatio = 100;
            if (state == "Typical")
            	depositRatio = 100;
            else if (state == "VIP")
                depositRatio = 50;
            else if (state == "Golden")
                depositRatio = 0;
            double deposit = final_price * depositRatio / 100;
            
            // 2.2.3 Check for promotion
            total += amount[i];
            if (total > 10000) 
                state = "Golden";
            else if (total > 5000)
                state = "VIP";
                
            System.out.println ("Selling price: $" + amount[i] + ", Discounted price: $" + 
            final_price + ", Deposit: $" + deposit + ", Type: " + state);   

        }
        
    }
    
}
