
public class SystemDate extends Day {

	// Singleton
	private static SystemDate theSystemDate = null;

	public static void initiateSystemDateInstance(String strDay) {

		if (theSystemDate == null) {

			theSystemDate = new SystemDate(strDay);

		} else {
			System.out.println("Cannot create one more system date instance.");
		}

	}

	public static SystemDate getInstance() {
		return theSystemDate;
	}

	private SystemDate(String strDate) {
		super(strDate);
	}

}
