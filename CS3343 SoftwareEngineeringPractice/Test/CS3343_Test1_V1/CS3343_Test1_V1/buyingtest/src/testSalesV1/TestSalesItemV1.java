package testSalesV1;

import salesV1.*;
import org.junit.Test;
import static org.junit.Assert.*;

public class TestSalesItemV1 {
	// Hint:
	// Enum Category can be declared as e.g. "Category.GARDEN, Category.BEVERAGE
	// ..."
	// For comparing double in JUnit
	// assertEquals (double, double, delta) , delta can be 0 .
	// e.g. assertEquals (10.00, 10.00, 0);
	// Add your answers to their respective test cases below.

	// Add your answer to the six test cases for Q1
	@Test
	public void testQ1_1() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BEVERAGE;
		double result = salesItem.getDiscountRate(cat, 0);
		assertEquals(-1.00, result, 0);
	}

	@Test
	public void testQ1_2() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BOOK;
		double result = salesItem.getDiscountRate(cat, 1);
		assertEquals(0.90, result, 0);
	}

	@Test
	public void testQ1_3() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.FOOD;
		double result = salesItem.getDiscountRate(cat, 11);
		assertEquals(0.90, result, 0);
	}

	@Test
	public void testQ1_4() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.FOOD;
		double result = salesItem.getDiscountRate(cat, 2);
		assertEquals(1.0, result, 0);
	}

	@Test
	public void testQ1_5() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BEVERAGE;
		double result = salesItem.getDiscountRate(cat, 4);
		assertEquals(0.95, result, 0);
	}

	@Test
	public void testQ1_6() {
		BuyerV1 buyer = new BuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.OTHER;
		double result = salesItem.getDiscountRate(cat, 4);
		assertEquals(1.00, result, 0);
	}

	// Add your answer to the two test cases for Q2
	@Test
	public void testQ2_1() {
		class StubBuyerV1 extends BuyerV1{
			//Overwrite the class functions
			public boolean isBirthdayThisWeek (){
				return true;
			}
		}
		BuyerV1 buyer = new StubBuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BOOK;
		double result = salesItem.getDiscountRate(cat, 6);
		assertEquals(0.50*0.90, result, 0.000001);
	}

	@Test
	public void testQ2_2() {
		class StubBuyerV1 extends BuyerV1{
			//Overwrite the class functions
			public boolean isBirthdayThisWeek (){
				return true;
			}
		}
		BuyerV1 buyer = new StubBuyerV1();
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BOOK;
		double result = salesItem.getDiscountRate(cat, 4);
		assertEquals(0.85*0.90, result, 0.000001);
	}

	// Add your answer to the two test cases for Q3
	@Test
	public void testQ3_1() {
		BuyerV1 buyer = new BuyerV1("Jackson", 12, 10);
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BOOK;
		double result = salesItem.getDiscountRate(cat, 6);
		assertEquals(0.50*0.90, result, 0.000001);
	}

	@Test
	public void testQ3_2() {
		BuyerV1 buyer = new BuyerV1("Jackson", 12, 10);
		SalesItemV1 salesItem = new SalesItemV1(buyer);
		CategoryV1 cat = CategoryV1.BOOK;
		double result = salesItem.getDiscountRate(cat, 4);
		assertEquals(0.85*0.90, result, 0.000001);

	}

}
