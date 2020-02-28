package testDaysMonthV1;

import static org.junit.Assert.*;
import org.junit.Test;

import daysmonthV1.*;

public class TestDaysMonthV1 {

	// Add your answer to the four test cases for Q1
	@Test
	public void testQ1_1() {
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(3,1997);
		System.out.println(result);
		assertEquals(31,result);
	}

	@Test
	public void testQ1_2() {;
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(11,2019);
		assertEquals(30,result);
	}

	@Test
	public void testQ1_3() {
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(13,1);
		assertEquals(-2,result);
	}

	@Test
	public void testQ1_4() {
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(9,-2);
		assertEquals(-1,result);
	}


	// Add your answer to the two test cases for Q2
	@Test
	public void testQ2_1() {
		class LeapYearV1Stub extends LeapYearV1{
			public boolean isLeapYear(int year) {
				return year == 2020;
			}
		}
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(new LeapYearV1Stub());
		int result = daysNumInMonthV1.getDaysNuminMonth(2,2020);
		assertEquals(29,result);
	}

	@Test
	public void testQ2_2() {
		class LeapYearV1Stub extends LeapYearV1{
			public boolean isLeapYear(int year) {
				return year == 2020;
			}
		}
		LeapYearV1Stub leapYearV1Stub = new LeapYearV1Stub();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(2,2019);
	}

	// Add your answer to the two test cases for Q3
	@Test
	public void testQ3_1() {
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(2,2020);
		assertEquals(29,result);
	}

	@Test
	public void testQ3_2() {
		LeapYearV1 leapYearV1Stub = new LeapYearV1();
		DaysNuminMonthV1 daysNumInMonthV1 = new DaysNuminMonthV1(leapYearV1Stub);
		int result = daysNumInMonthV1.getDaysNuminMonth(2,2019);
		assertEquals(28,result);
	}

}
