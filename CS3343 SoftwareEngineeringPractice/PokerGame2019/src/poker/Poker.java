package poker;

public class Poker {
	// Precondition: A hand of n cards have been sorted by card number.
	public boolean isFullHouse(String cards[], int n) {
		return isThreeOfaKind(cards, n) && isTwoPairs(cards, n) && !isFourOfAKind(cards,n);
	}

	// Precondition: A hand of n cards have been sorted by card number.
	public boolean isThreeOfaKind(String cards[], int n) {
		for (int i=0; i<n-2; i++) {
			if (cards[i].charAt(1) == cards[i+1].charAt(1) &&
					cards[i+1].charAt(1) == cards[i+2].charAt(1))
					return true;
		}

		return false;
	}

	// Precondition: A hand of n cards have been sorted by card number.
	public boolean isTwoPairs(String cards[], int n) {
		int count = 0;
		for (int i=0; i<n-1; i++) {
			if (cards[i].charAt(1) == cards[i+1].charAt(1)) {
				count++;
				i++;
			}
		}
		if (count == 2)
			return true;
		else
			return false;
	}
	
	public boolean isFourOfAKind(String cards[], int n) {
		char a,b='_';
		boolean ba[]= {false,false,false,false} ,bb[]=  {false,false,false,false}; // C, D, S, H
		a = cards[0].charAt(1);
		switch(cards[0].charAt(0)) {
		case 'C':
			ba[0] = true;
			break;
		case 'D':
			ba[1] = true;
			break;
		case 'S':
			ba[2] = true;
			break;
		case 'H':
			ba[3] = true;
			break;
		}
		for (int i = 1; i < cards.length;i++) {
			if (cards[i].charAt(1) == a) {
				switch(cards[i].charAt(0)) {
				case 'C':
					ba[0] = true;
					break;
				case 'D':
					ba[1] = true;
					break;
				case 'S':
					ba[2] = true;
					break;
				case 'H':
					ba[3] = true;
					break;
				}
			}else {
				if ( b != '_' && b != cards[i].charAt(1)) {
					return false;
				}else {
					if (b == '_') {
						b = cards[i].charAt(1);
					}
					switch(cards[i].charAt(0)) {
					case 'C':
						bb[0] = true;
						break;
					case 'D':
						bb[1] = true;
						break;
					case 'S':
						bb[2] = true;
						break;
					case 'H':
						bb[3] = true;
						break;
					}
				}
			}
		}
		
		return Poker.arrayAllTrue(bb) || Poker.arrayAllTrue(ba);
		
	}
	
	public static boolean arrayAllTrue(boolean arr[]) {
		for (boolean s: arr) {
			if (!s) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String args[]) {
		System.out.println(new Poker().isFullHouse(
			new String[] {"C2", "D2", "H2", "S3", "S4"}, 5));
	}
}
// end of Poker.java
