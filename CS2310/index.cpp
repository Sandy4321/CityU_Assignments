#include<iostream>

using namespace std;

int main(){

	int length ;
	cout << "Please input the length (integer):" << endl ;
	cin >> length ;
	int halfLength = length / 2 ;

	char direction ;
	cout << "Do you want to print U or D?:" << endl ;
	cin >> direction ;
	cout << endl;

	string arrow = "";

	if ( direction == 'U' ) {

		for ( int i = 0 ; i < length ; i ++ ) {
			// create the left side of arrow
			for ( int position = 0 ; position < halfLength - 1 ; position++ ) {
				if ( position == halfLength - 1 - i ) {
					arrow += "*" ;
				} else {
					arrow += " " ;
				}
			}

			// create the center of arrow
			arrow += "*" ;

			// create the right side of arrow
			for ( int position = 0 ; position < halfLength - 1 ; position++ ) {
				if ( position == i - 1 ) {
					arrow += "*" ;
				} else {
					arrow += " " ;
				}
			}

			arrow += "\n" ;
		}

		cout << arrow << endl;

	} else if ( direction == 'D' ) {

		for ( int i = 0 ; i < length ; i ++ ) {
			// create the left side of arrow
			for ( int position = 0 ; position < halfLength - 1 ; position++ ) {
				if ( position == halfLength - 1 - i ) {
					arrow += "*" ;
				} else {
					arrow += " " ;
				}
			}

			// create the center of arrow
			arrow += "*" ;

			// create the right side of arrow
			for ( int position = 0 ; position < halfLength - 1 ; position++ ) {
				if ( position == i - 1 ) {
					arrow += "*" ;
				} else {
					arrow += " " ;
				}
			}

			arrow += "\n" ;
		}

		cout << arrow << endl;
		
	} else {

		cout << "Invalid input!" << endl;

	}
	

	return 0;
}