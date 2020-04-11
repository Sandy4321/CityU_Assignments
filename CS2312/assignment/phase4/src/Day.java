public class Day implements Cloneable, Comparable<Day> {

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
	
	@Override
	public int compareTo ( Day anotherDay ) {
		
		int currDateInt = this.year * 10000 + this.month * 100 + this.day;
		int anotherDateInt = anotherDay.year * 10000 + anotherDay.month * 100 + anotherDay.day;
		return currDateInt - anotherDateInt;
	}
	
	public static int dayDifference ( Day beforeDate, Day afterDate ) {
		
		boolean isReversed = false;
		if ( beforeDate.compareTo(afterDate) > 0) {
			Day temp = afterDate;
			afterDate = beforeDate ;
			beforeDate = temp;
			isReversed=true;
		}
		
		int totalDays = 0;

		if (beforeDate.year != afterDate.year) {
			
			int startYear = beforeDate.year + 1;
			while (startYear < afterDate.year) { // calculating days from (beforeDate.year to afterDate.year) exclusive of both start and afterDate year
				if (isLeapYear(startYear)) {
					totalDays ++;
				}
				totalDays += 365;
				startYear++;
			}
		
			int startMonth = beforeDate.month + 1;
			while (startMonth <= 12) { // calculating days from (beforeDate.month to 12) exclusive of the first month // 12 because end of year 
				totalDays += daysInMonth(startMonth, beforeDate.year);
				startMonth++;
			}
			
			startMonth = 1;
			while (startMonth < afterDate.month) { // calculating days from (1 to afterDate.month) exclusive of the end month // 1 because end of month;
				totalDays += daysInMonth(startMonth, afterDate.year);
				startMonth++;
			}
			
		}else{
			
			// they are within the same year
			int startMonth = beforeDate.month+1;
			while (startMonth < afterDate.month) {
				totalDays += daysInMonth(startMonth, beforeDate.year);
			}
			
			if (beforeDate.month == afterDate.month) {
				
				int startDay = beforeDate.day;
				while ( startDay <= afterDate.day && valid(beforeDate.year, beforeDate.month , startDay)) { // calculating days from (beforeDate.day to [28/29/30/31]) depending of start.month
					totalDays++;
					startDay++;
				}
				
				return totalDays;
				// The rest no need to consider. if in same month and same year
			}
			
		}
		
		int startDay = beforeDate.day;
		while (valid(beforeDate.year, beforeDate.month , startDay)) { // calculating days from (beforeDate.day to [28/29/30/31]) depending of start.month
			totalDays++;
			startDay++;
		}
		
		startDay = afterDate.day;
		while (valid(afterDate.year,afterDate.month,startDay)) { // reversely minus 
			totalDays++;
			startDay--;
		}
		
		return isReversed? -1*totalDays :totalDays;
		
	}
	
	public void set ( String strDay ){
		
		String[] dayArgs = strDay.split( "-" );
		
		this.day 	= Integer.parseInt( dayArgs[0] );
		this.month 	= ( MonthNames.indexOf( dayArgs[1] ) / 3 ) + 1;
		this.year 	= Integer.parseInt( dayArgs[2] );
		
		
	}
	
	@Override
	public String toString () {
		return this.day +"-"+ MonthNames.substring((this.month -1) * 3 ,this.month * 3) +"-"+ this.year;
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
//		switch (month) {
//			case 1:		case 3:		case 5:
//			case 7:		case 8:		case 10:
//			case 12:
//				return day <= 31;
//			case 4:		case 6:		case 9:
//			case 11:
//				return day <= 30;
//			case 2:
//				if ( isLeapYear( year ) )
//					return day <= 29;
//				else
//					return day <= 28;
//		}
		int daysOfMonth = daysInMonth(month, year);
		if (daysOfMonth != -1) {
			return day <= daysOfMonth;
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
	
	public static int daysInMonth(int month , int year) {
		switch (month) {
			case 1:		case 3:		case 5:
			case 7:		case 8:		case 10:
			case 12:
				return 31;
			case 4:		case 6:		case 9:
			case 11:
				return 30;
			case 2:
				if ( isLeapYear( year ) )
					return 29;
				else
					return 28;
		}
		return -1;
	}
	
	
	/*
	 * things missing:
	 * 1. day difference,
	 * 2. leap year consideration
	 * 3. 
	 * */
}
