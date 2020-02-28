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

	
	
	// Return an integer that is the reversed version of the input integer x (without the 0 digit). eg. 1234=>4321 
	static int reverse(int x) // 1234 => 4321
	{
		//todo
		if(x<10) {
			return x;
		}
		return leftMostDigit(x) + reverse(tail(x))*10; // x=1234 return 1 + (432)*10  , x= 234 => return  2 + (43)*10 , x=34 => return  3 + (4*10), x=4 return 4;
	}


	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		
		int x;
		System.out.print("input x (-1 to end) : "); x=s.nextInt();

		while (x!=-1)
		{
			System.out.println(reverse(x));
			
			System.out.print("input x (-1 to end) : "); x=s.nextInt();
		}

		s.close();
	}
}