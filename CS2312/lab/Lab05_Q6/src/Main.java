

import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws FileNotFoundException 
	{
		//Read input file pathname
		Scanner in = new Scanner(System.in); 
		System.out.print("Please enter the filename: ");
		String filepathname = in.next();

		//Grab the StatisticsSystem ss and add counters 
		StatisticsSystem ss = StatisticsSystem.getInstance();  
		ss.addCounter(new Counter());
		ss.addCounter(new AreaCounter("YuenLong")); //to be replaced by Part(a)(ii)
		ss.addCounter(new AreaCounter("KwunTong")); //to be replaced by Part(a)(ii)

		//TODO: Part (a)(ii), (b)
		
		//The ss will load file data and tell its counters to count 
		ss.countData(filepathname);		
		
		//The ss will tell its counters to report
		ss.report();
		
		in.close();
	}
}