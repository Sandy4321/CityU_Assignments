
public class Cat extends Animal {

	public Cat(String n) {
		super(n);
		// TODO Auto-generated constructor stub
	}

	@Override
	public int getRunSpeed() {
		return 5;
	}

	@Override
	public String getMyName() {
		// TODO Auto-generated method stub
		return getName();
	}
	
	public void chase(Runnable target) {
		if (target.getRunSpeed() < getRunSpeed()) {
			System.out.println(getName() + " Catches " + target.getMyName() );		
		}else {
			System.out.println(getName() + " Cannot Catch "+ target.getMyName() );
		}
	}

}
