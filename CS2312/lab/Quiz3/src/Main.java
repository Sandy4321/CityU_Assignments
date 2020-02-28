public class Main {
	public static void main(String[] args) {
		
		Product p1 = new Product("P001", 100); // id and price
		Product p2 = new Product("P002", 200);
		Product p3 = new Product("P003", 300);
		
		Service s1 = new Service("S001", 150); // id and price
		Service s2 = new Service("S002", 250);
		Service s3 = new Service("S003", 350);
		
		Customer c1 = new Customer("Helena"); // customer name
		Customer c2 = new Customer("Mary");
		Customer c3 = new Customer("Paul");
		
		Shop h1 = new Shop("Shop A", new Tradable[] { p1, s1 }); // Shop name, products and services
		Shop h2 = new Shop("Shop B", new Tradable[] { p1, p2, p3 });
		Shop h3 = new Shop("Shop C", new Tradable[] { s1, s2, s3 });
		
		c1.order(s1, h1);
		c2.order(p1, h2);
		c3.order(p2, h3);
	}
}