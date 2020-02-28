public class Main {
	public static void main(String[] args){
		Hero hero = new Hero();
		Monster m = new Monster();
		Weapon p = new Sword();
		
		hero.kill(m,p);
	}
}
