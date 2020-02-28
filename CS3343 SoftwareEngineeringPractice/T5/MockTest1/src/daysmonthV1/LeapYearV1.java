package daysmonthV1;

public class LeapYearV1 {
	public boolean isLeapYear(int year) {
		boolean leap;
		if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
			leap = true;
		else
			leap = false;
		return leap;
	}
}
