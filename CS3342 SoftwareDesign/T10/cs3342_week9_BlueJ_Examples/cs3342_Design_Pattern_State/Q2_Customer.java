public class Q2_Customer
{
    private String membership;
    private int total_expenses; 
  
    public Q2_Customer(){
       membership = "Green";
    }
    public int getDiscount(){
        if (membership == "Silver")
            return 80;
        else if (membership == "Gold")
            return 50;
        else // else no discount, Green 
            return 100;
    }
    public int getDeposit(){
        if (membership == "Silver")
            return 50;
        else if (membership == "Gold")
            return 0;
        else // else full deposit, Green 
            return 100;
    }
    public String getType(){
        return membership;
    }
    public int getExpenses(){
        return 1;
    }
    public void newExpense(int amount){
        total_expenses += amount;
        if (total_expenses > 10000)
            membership = "Gold";
        else if (total_expenses > 5000)
            membership = "Silver";
    } 
}
