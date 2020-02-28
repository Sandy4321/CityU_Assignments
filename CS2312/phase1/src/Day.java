import java.util.Arrays;

public class Day implements Cloneable {

	private static final String MonthNames = "JanFebMarAprMayJunJulAugSepOctNovDec";
	
	private int year;
	private int month;
	private int day;
	
	public Day ( int year , int month , int day ) {
		this.year = year;
		this.month = month; 
		this.day = day;
	}
	
	public Day ( String strDay ){
		set( strDay ) ;
	}
	
	public void set ( String strDay ){
		
		String[] dayArgs = strDay.split( "-" );
		
		this.day 	= Integer.parseInt( dayArgs[0] );
		this.month 	= ( MonthNames.indexOf( dayArgs[1] ) / 3 ) + 1;
		this.year 	= Integer.parseInt( dayArgs[2] );
		
		
	}
	
	public String toString () {
		return this.day +"-"+ this.MonthNames.substring((this.month -1) * 3 ,this.month * 3) +"-"+ this.year;
	}
	
	public Day clone () { // considering another cloning method super.clone();
		Day copy = null;
		try {
			copy = (Day)super.clone();
		} catch (CloneNotSupportedException exception) {
			exception.printStackTrace();
		}
		return copy;
	}
	
	
	// Static Methods
	public static boolean valid ( int year, int month, int day ) {
		if ( month < 1 || month > 12 || day < 1 )
			return false;
		switch (month) {
			case 1:		case 3:		case 5:
			case 7:		case 8:		case 10:
			case 12:
				return day <= 31;
			case 4:		case 6:		case 9:
			case 11:
				return day <= 30;
			case 2:
				if ( isLeapYear( year ) )
					return day <= 29;
				else
					return day <= 28;
		}
		return false;
	}
	
	public static boolean isLeapYear ( int year ) {
		if (year % 400 == 0)
			return true;
		else if (year % 100 == 0)
			return false;
		else if (year % 4 == 0)
			return true;
		else
			return false;
	}
	
	
	
	/*
	 * things missing:
	 * 1. day difference,
	 * 2. leap year consideration
	 * 3. 
	 * */
}
