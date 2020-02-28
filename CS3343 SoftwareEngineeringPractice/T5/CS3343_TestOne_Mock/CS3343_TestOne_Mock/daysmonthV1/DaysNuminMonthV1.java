package daysmonthV1;

public class DaysNuminMonthV1 {
	LeapYearV1 leapYear;

	public DaysNuminMonthV1(LeapYearV1 leapYear) {
		this.leapYear = leapYear;
	}

	public int getDaysNuminMonth(int month, int year) {
		int daysNum;
		if (year < 1) {
			daysNum = -1;
			return daysNum;
		}

		MonthV1 inputMonth = MonthV1.monthIntToEnum(month);
		if (inputMonth == MonthV1.JANUARY || inputMonth == MonthV1.MARCH || inputMonth == MonthV1.MAY
				|| inputMonth == MonthV1.JULY || inputMonth == MonthV1.AUGUST || inputMonth == MonthV1.OCTOBER
				|| inputMonth == MonthV1.DECEMBER) {
			daysNum = 31;
		} else if (inputMonth == MonthV1.APRIL || inputMonth == MonthV1.JUNE || inputMonth == MonthV1.SEPTEMBER
				|| inputMonth == MonthV1.NOVEMBER) {
			daysNum = 30;
		} else if (inputMonth == MonthV1.FEBRUARY) {
			if (leapYear.isLeapYear(year)) {// This statement is labeled as L1.
				daysNum = 29;
			} else {
				daysNum = 28;
			}
		} else
			daysNum = -2;
		return daysNum;
	}
}
