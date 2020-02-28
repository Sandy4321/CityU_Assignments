
public class Cannon extends Weapon
{
    // A sword hurts a monster with 5 additional damage points
    // on top of the damaged made by a general Weapon.
    public void attack (Monster m) {
        super.attack(m);
        //additional damage
        m.hurt(10);
    }
}
