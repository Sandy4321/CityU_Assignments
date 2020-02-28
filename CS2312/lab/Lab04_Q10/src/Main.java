import java.util.*;

public class Main
{
	
	// todo: Add required methods below
	//	
	static int tail(int x) // 1234 => 234
	{	
		if(x<10) {
			return 0;
		} else {
			return x%10 + tail(x/10)*10; // 234 => 2
		}
	}
	
	static int leftMostDigit(int x)
	{	
		if(x < 10) {
			return x;
		}else {
			return leftMostDigit(x/10);
		}
	}
	

	// Determine whether the sequences of digits in 2 integers (without the 0 digit) are opposite to one another (eg. 123 and 321)
	static boolean areOpposite(int x1, int x2)
	{	
		if (x1 < 10) {
			return x1 == x2; // no need to check if x2 is smaller than 10 because x2 will not be equal to x1 if it is not smaller than 10 which should return false anyway.
		}
		return leftMostDigit(x1) == x2%10 && areOpposite(tail(x1),x2/10);
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int x1,x2;
		System.out.print("input 2 integers, separated by a space (\"-1 -1\" to end) : "); 
		x1=s.nextInt();x2=s.nextInt();

		while (x1!=-1)
		{
			if (areOpposite(x1,x2)) 
				System.out.println("true");
			else
				System.out.println("false");
			
			System.out.print("input 2 integers, separated by a space (\"-1 -1\" to end) : "); 
			x1=s.nextInt();x2=s.nextInt();
			System.out.println();
		}

		s.close();
	}
}