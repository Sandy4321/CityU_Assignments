#include <vector>
#include <iostream>

using namespace std;


int combineTwo (int first , int second) {
	return (first << 5) + second;
}

int* splitTwo (int num) {
	int res [ 2 ] = { 0 };
	for (int i = 0;i < 5;i++) {
		res [ 0 ] += (num % 2) << i;
		num >>= 1;
	}
	for (int i = 0; i < 3; i++) {
		res [ 1 ] += (num % 2) << i;
		num >>= 1;
	}
	return res;
}


vector<int> printAsBit (int a , int size) {
	vector<int> res;
	for (int i = 0;i < size;i++) {
		//a -> bit
		res.push_back (a % 2);
		a >>= 1;
	}
	return res;
}

int main () {

	char* line = new char [ 9 ];
	while (cin >> line) {
		int memo [ 32 ] [ 2 ] = { 0 };

		memo [ 0 ] [ 0 ] = (((line [ 0 ] - 48) << 2) + ((line [ 1 ] - 48) << 1) + (line [ 2 ] - 48));
		memo [ 0 ] [ 1 ] = (((line [ 3 ] - 48) << 4) + ((line [ 4 ] - 48) << 3) + ((line [ 5 ] - 48) << 2) + ((line [ 6 ] - 48) << 1) + (line [ 7 ] - 48));

		/*int temNum;
		cin >> temNum;
		int* temp = splitTwo(temNum);
		cout << temp[0] << "," << temp[1] << endl;*/

		for (int i = 1;i < 32; i++) {
			cin >> line;
			memo [ i ] [ 0 ] = (((line [ 0 ] - 48) << 2) + ((line [ 1 ] - 48) << 1) + (line [ 2 ] - 48));

			memo [ i ] [ 1 ] = (((line [ 3 ] - 48) << 4) + ((line [ 4 ] - 48) << 3) + ((line [ 5 ] - 48) << 2) + ((line [ 6 ] - 48) << 1) + (line [ 7 ] - 48));

		}

		int ac = 0;
		int pc = 0;
		bool ended = false;
		while (!ended) {
			//cout << "line : " << pc << " is lead: " << memo[pc][0] << " by: " << memo[pc][1] << endl;
			int copy = memo [ pc ] [ 1 ];
			int task = memo[pc][0];
			
			switch (task) {
			case 0: {
				int* temp = splitTwo (ac);
				memo [ copy ] [ 0 ] = temp [ 1 ];
				memo [ copy ] [ 1 ] = temp [ 0 ];
				// consider storing to self? what will happend
				break;
			}
			case 1:
				ac = combineTwo (memo [ copy ] [ 0 ] , memo [ copy ] [ 1 ]);
				break;
			case 2:
				if (ac == 0) {
					pc = copy;
					pc--;
				}
				break;
			case 3:
				break;
			case 4:
				ac--;
				if (ac < 0) {
					ac = 255;
				}
				break;
			case 5:
				ac++;
				if (ac > 255) {
					ac = 0;
				}
				break;
			case 6:
				pc = copy;
				pc--;
				break;
			case 7:
				ended = true;
				break;
			}
			pc++;
			if (pc > 31) {
				pc = 0;
			}

		}


		vector<int> res = printAsBit (ac , 8);

		for (int i = 0; i < 8;i++) {
			cout << res.at (res.size () - i - 1);
		}
		cout << endl;

	}


	return 0;
}