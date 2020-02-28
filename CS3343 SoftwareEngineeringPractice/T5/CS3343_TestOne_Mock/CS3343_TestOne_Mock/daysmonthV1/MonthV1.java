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
}
