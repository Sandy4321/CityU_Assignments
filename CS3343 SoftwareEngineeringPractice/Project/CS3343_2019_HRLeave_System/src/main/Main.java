package main;

public class Main{
	
	
	public static void main(String[] args) throws Exception {
		
		Backend backend = Backend.getInstance();
		Frontend frontend = Frontend.getInstance();
		frontend.start();
		frontend.addObserver(backend);
		
	}
	
}
