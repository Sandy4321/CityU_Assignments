package daysmonthV1;

public enum MonthV1 {
	INVALID(0), 
	JANUARY(1), 
	FEBRUARY(2), 
	MARCH(3), 
	APRIL(4), 
	MAY(5), 
	JUNE(6), 
	JULY(7), 
	AUGUST(8), 
	SEPTEMBER(9), 
	OCTOBER(10), 
	NOVEMBER(11), 
	DECEMBER(12);

	private int month;

	private MonthV1(int month) {
		this.month = month;
	}

	public static MonthV1 monthIntToEnum(int x) {
		switch (x) {
		case 1:
			return JANUARY;
		case 2:
			return FEBRUARY;
		case 3:
			return MARCH;
		case 4:
			return APRIL;
		case 5:
			return MAY;
		case 6:
			return JUNE;
		case 7:
			return JULY;
		case 8:
			return AUGUST;
		case 9:
			return SEPTEMBER;
		case 10:
			return OCTOBER;
		case 11:
			return NOVEMBER;
		case 12:
			return DECEMBER;
		default:
			return INVALID;
		}
	}
	
	public static int daysNumInMonth(int month, boolean isLeapYear) {
		int daysNum;
		MonthV1 inputMonth = MonthV1.monthIntToEnum(month);
		if (inputMonth == MonthV1.JANUARY || inputMonth == MonthV1.MARCH || inputMonth == MonthV1.MAY
				|| inputMonth == MonthV1.JULY || inputMonth == MonthV1.AUGUST || inputMonth == MonthV1.OCTOBER
				|| inputMonth == MonthV1.DECEMBER) {
			daysNum = 31;
		} else if (inputMonth == MonthV1.APRIL || inputMonth == MonthV1.JUNE || inputMonth == MonthV1.SEPTEMBER
				|| inputMonth == MonthV1.NOVEMBER) {
			daysNum = 30;
		} else if (inputMonth == MonthV1.FEBRUARY) {
			if (isLeapYear) {// This statement is labeled as L1.
				daysNum = 29;
			} else {
				daysNum = 28;
			}
		} else
			daysNum = -2;
		return daysNum;
	}
}
