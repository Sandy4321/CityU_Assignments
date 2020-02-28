public class Customer
{
    private Membership membership;
    private int total_expenses; 
   
    public Customer(){ 
       membership = Green.getInstance();
    }
    public int getDiscount(){
        return membership.discount();
    }
    public int getDeposit(){
        return membership.deposit();
    }
    public String getType(){
        return membership.type();
    }
    public int getExpenses(){
        return total_expenses;
    }
    public void newExpense(int amount){
        total_expenses += amount;
        if (total_expenses > 10000)
            membership = Gold.getInstance();
        else if (total_expenses > 5000)
            membership = Silver.getInstance();
    } 
}

