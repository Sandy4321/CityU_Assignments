import java.util.*;

public class Main
{
	//Return the largest digit in an integer n.
	
	static int result = 0;
	
	static int getLargestDigit(int n)
	{
		if (n<10)
		{
			return n;
		}
		else
		{	
			int a = getLargestDigit(n/10);
			if(n%10 < a) {
				return a;
			}else {
				return n%10;
			}
		}
	}

	public static void main(String[] args)
	{
		System.out.print("Input n: ");
		Scanner s = new Scanner(System.in);
		int n=s.nextInt();
		
		System.out.println(getLargestDigit(n));

		s.close();
	}
}