class A {
	
	private int i;
	private static int j;
	
	public static void f1() {
//		i++;	//line 1			Error : No object/instance to refer to i
	}
	
	public void f2() {
		i++;	//line 2
	}
	
	public static void f3() {
		j++;	//line 3
	}	
	
	public void f4() {
		j++;	//line 4
	}
	
}


public class Main
{
	public static void main(String[] args) 
	{
		A obj = new A();
		
		obj.f1();	// line 5			Compiler warning : f1 is a static method but used as a instance/non-static method
		obj.f2();	// line 6
		obj.f3();   // line 7			Compiler warning : f3 is a static method but used as a instance/non-static method
		obj.f4();   // line 8
		
		A.f1();     // line 9
//		A.f2();     // line 10			Error : calling f2 require an object
		A.f3();     // line 11
//		A.f4();     // line 12			Error : calling f4 require an object
	}
}