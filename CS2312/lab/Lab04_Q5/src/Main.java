import java.util.*;

public class Main
{
	// determine whether a given digit exists in an integer x.  	
	static boolean containDigit(int x, int d)
	{	
		if(x < 10) {
			return x == d;
		}else {
			return x%10 == d || containDigit(x/10,d);
		}
	}

	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int x,d;
		System.out.print("input x and d, separated by a space (\"-1 -1\" to end) : "); 
		x=s.nextInt();d=s.nextInt();

		while (x!=-1)
		{
			if (containDigit(x,d)) 
				System.out.println("true");
			else
				System.out.println("false");
			
			System.out.print("input x and d, separated by a space (\"-1 -1\" to end) : "); 
			x=s.nextInt();d=s.nextInt();
		}

		s.close();
	}
}