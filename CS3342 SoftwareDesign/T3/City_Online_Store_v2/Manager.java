public class Manager
{
    private Customer c; 
    
    public Manager ()
    {
        c = new Customer();
    }
    
    public void process (double amount)
    {
       double final_price = amount * c.discount() / 100;
       double deposit = final_price * c.deposit() / 100;
       
       c.promote(amount);
       
       System.out.println ("Selling price: $" + amount + ", Discounted price: $" + final_price + 
       ", Deposit: $" + deposit + ", Type: " + c.type());   
    }
}
