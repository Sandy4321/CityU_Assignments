public class Person 
{
	public Playables getPlay(String toyName) {
		if(toyName.equals("Piano")) {
			 return new Piano();
		}else if (toyName.equals("Football")){
			return new Football();
		}else if (toyName.equals("Chess")) {
			return new Chess();
		}else {
			return null;
		}
	}
}
