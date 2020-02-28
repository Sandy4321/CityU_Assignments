
public class Monster {
	//The initial life is 100
	public Monster(){
		life = 100;
	}
	//when a monster is hurt, its life is reduce by the number of damage
	void hurt(int damage) {
		life = life - damage;
		if (life <= 0){
			life = 0;
		}
	}
	//if its life is 0, then it is dead else it is alive
	boolean isAlive() {
		if (life >0) {
			return true;
		}else {
			return false;
		}
	}
	private int life;
}
