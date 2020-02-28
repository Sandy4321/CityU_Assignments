package testcase;

import poker.Poker;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;


public class PokerTest {
	private Poker poker;

    /**
     * Sets up the test fixture.
     * 
     * Called before every test case method.
     */
    @Before
    public void setUp() { poker = new Poker(); }

    /**
     * Tears down the test fixture.
     * 
     * Called after every test case method.
     */
    @After
    public void tearDown() {}

    /*
    // Test case 1: n = 0, cards = { }
    @Test
    public void testNoCards() {
        boolean result;
        String[] input = null;
        result = poker.isFullHouse(input, 0);
        assertEquals(false, result);
    }

    // Test case 2: n = 5, cards = {"C2", "D2", "H2", "S3", "S4"};
    @Test
    public void test22234() {
        boolean result;
        String[] input = new String[] {"C2", "D2", "H2", "S3", "S4"};
        result = poker.isFullHouse(input, 5);
        assertEquals(false, result);
    }
    */
    
    
    @Test
    public void testNoCards() {
    	assertEquals(false,this.poker.isFullHouse( new String[] {}, 0));
    }
    
    @Test
    public void test22234() {
    	assertEquals(false,this.poker.isFullHouse(new String[] {"C2" ,"D2","H2","S3","S4"},5));
    }
    
    @Test
    public void testJJKKK() {
    	assertEquals(true,this.poker.isFullHouse(new String[] {"DJ" ,"SJ","CK","DK","HK"},5));
    }
    
    @Test
    public void test333XX() {
    	assertEquals(true,this.poker.isFullHouse(new String[] {"C3" ,"D3","S3","HX","SX"},5));
    }
    
    @Test
    public void test22334() {
    	assertEquals(false,this.poker.isFullHouse(new String[] {"C2" ,"D2","C3","D3","C4"},5));
    }
    
    @Test
    public void testA2345() {
    	assertEquals(false,this.poker.isFullHouse(new String[] {"CA", "C2", "C3", "C4", "C5"},5));
    }
    
    @Test
    public void test66667() {
    	assertEquals(false,this.poker.isFullHouse(new String[] {"C6", "D6", "H6", "S6", "D7"},5));
    }
    
    @Test
    public void testAXXXX() {
    	assertEquals(false,this.poker.isFullHouse(new String[]{"CA", "DX", "HX", "SX", "DK"},5));
    }
    
    @Test
    public void testAXXXX() {
    	assertEquals(false,this.poker.isFullHouse(new String[]{"C2", "C2", "C2", "C2", "C2"},5));
    }
    
    /*
    // Test case 3: n = 5, cards = {"DJ", "SJ", "CK", "DK", "HK"};
    @Test
    public void testJJKKK() {
        boolean result;
        String[] input = new String[] {"DJ", "SJ", "CK", "DK", "HK"};
        result = poker.isFullHouse(input, 5);
        assertEquals(true, result);
    }
    // Test case 4: n = 5, cards = {"C3", "D3", "S3", "HX", "SX"};
    @Test
    public void test333XX() {
        boolean result;
        String[] input = new String[] {"C3", "D3", "S3", "HX", "SX"};
        result = poker.isFullHouse(input, 5);
        assertEquals(true, result);
    }
    // Test case 5: n = 5, cards = {"C2", "D2", "C3", "D3", "C4"};
    @Test
    public void test22334() {
        boolean result;
        String[] input = new String[] {"C2", "D2", "C3", "D3", "C4"};
        result = poker.isFullHouse(input, 5);
        assertEquals(false, result);
    }
    // Test case 6: n = 5, cards = {"CA", "C2", "C3", "C4", "C5"};
    @Test
    public void testA2345() {
        boolean result;
        String[] input = new String[] {"CA", "C2", "C3", "C4", "C5"};
        result = poker.isFullHouse(input, 5);
        assertEquals(false, result);
    }
    
     */
    /*

    // Test case 7: n = 5, cards = {"C6", "D6", "H6", "S6", "D7"};
    @Test
    public void test66667() {
        boolean result;
        String[] input = new String[] {"C6", "D6", "H6", "S6", "D7"};
        result = poker.isFullHouse(input, 5);
        assertEquals(false, result);
    }
    // Test case 8: n = 5, cards = {"CA", "DX", "HX", "SX", "DK"};
    @Test
    public void testAXXXK() {
        boolean result;
        String[] input = new String[] {"CA", "DX", "HX", "SX", "DK"};
        result = poker.isFullHouse(input, 5);
        assertEquals(false, result);
    }
    */

}

