public class Main
{
	public static void main(String[] args){
		Phone p = new Phone();
		System.out.printf ("Current Battery(New): %.2f\n", p.getBattery());
		
		operatePhone("game", p, 3);
		operatePhone("charge", p, 2);
		operatePhone("music", p, 4);
		
	}
	
	public static void operatePhone( String cmd, Phone p, int hour) {
		//Playing game for an hour will reduce the battery life by 0.2
		if (cmd.equals("game")) {
			p.be_played_for(hour);
		}
		//Recharging the phone for an hour will increase the battery life by 0.5
		if (cmd.equals("charge")) {
		    p.be_charged_for(hour);
		}
		//Calculate the battery consumption to play music 
		//for the inputted amount of time as represented by the parameter "hour"
		if (cmd.equals("music")) {
			p.be_played_music_for(hour);
		}
		//Display the remaining battery life
		double currentBattery = p.getBattery();
		System.out.printf("Current battery: %.2f\n", currentBattery);
	}

}
