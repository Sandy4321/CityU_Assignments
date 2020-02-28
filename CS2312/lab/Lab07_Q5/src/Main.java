class C{
	
}
class A extends C {	
	public int i; //JAVA: default initialization for numeric fields is 0
	public static int j; //JAVA: default initialization for numeric fields is 0
	A() {i++;j++;}
	public void fi() {i++;}
	public void fj() {j++;}
	public static void sj() {j++;}
}

class B extends A {
	public int i;
	public static int j;
	public void fi() {i++; super.super}
	public void fj() {j++;}
	public static void sj() {j++;}
}

public class Main 
{
	public static void main(String[] args) 
	{
		A a;	
		a = new A();  
		a.fi(); 
		a.fj();
		a.sj();
	
		
		B b;	 
		b = new B();	 
		b.fi(); 
		b.fj();
		b.sj();
		System.out.println(a.i+" "+a.j+" "+b.i+" "+b.j);

		A a1 = b;
		
	}
}