    public class Q1_Customer
{
    private Membership membership;
    private int total_expenses; 
  
    public Q1_Customer(){
       membership = new Green();
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
            membership = new Gold();
        else if (total_expenses > 5000)
            membership = new Silver();
    } 
}

