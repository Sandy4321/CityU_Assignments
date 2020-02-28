
public class Mouse extends Animal {

	public Mouse(String n) {
		super(n);
	}

	@Override
	public int getRunSpeed() {
		return 2;
	}

	@Override
	public String getMyName() {
		return getName();
	}

}
