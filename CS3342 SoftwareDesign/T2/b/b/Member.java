public class Member {

	private int id;
	private String name;
	private double fine;
	private int attribute;
	private MemberState ageGroup;

	public int getID() {
		// TODO - implement Member.getID
		throw new UnsupportedOperationException();
	}

	public String getName() {
		return this.name;
	}

	public void penalize() {
		// TODO - implement Member.penalize
		throw new UnsupportedOperationException();
	}

	/**
	 * 
	 * @param amount
	 */
	public void pay(double amount) {
		// TODO - implement Member.pay
		throw new UnsupportedOperationException();
	}

	public String toString() {
		// TODO - implement Member.toString
		throw new UnsupportedOperationException();
	}

	public MemberState getAgeGroup() {
		return this.ageGroup;
	}

	/**
	 * 
	 * @param ageGroup
	 */
	public void setAgeGroup(MemberState ageGroup) {
		this.ageGroup = ageGroup;
	}

}