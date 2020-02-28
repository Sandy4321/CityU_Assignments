import java.util.*;

public class Main
{
	
	// Determine whether integer x contains non-decreasing digits (eg. 1234, 14789, 224466)
	//i.e., whether the sequence of digits is "sorted" in ascending order.
	static boolean containNonDecreasingDigits(int x)
	{	
		if(x < 100) {
			return x%10 >= (x/10)%10; // because even if input is single digit eg: 9, 9%10 is 9 and (9/10)%10 is 0 and the second is always 0 so it will be true!
		}else {
			return (x%10 >= (x/10)%10) && containNonDecreasingDigits(x/10);
		}
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int x;
		System.out.print("input x (-1 to end) : "); x=s.nextInt();

		while (x!=-1)
		{
			if (containNonDecreasingDigits(x)) 
				System.out.println("true");
			else
				System.out.println("false");
			
			System.out.print("input x (-1 to end) : "); x=s.nextInt();
		}

		s.close();
	}
}