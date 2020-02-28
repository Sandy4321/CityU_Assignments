
public class Hero {
    
	//use a weapon to attack a monster until it is killed
    void kill(Monster m,Weapon p){
        while (m.isAlive()) {
            p.attack(m);
            System.out.println ("Attacking " + m.getClass().getName() + " using " + p.getClass().getName());
        }
    }
    
}
