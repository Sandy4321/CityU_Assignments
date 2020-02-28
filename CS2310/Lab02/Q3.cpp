#include <iostream>
using namespace std;

class A{
	private:
		int a;
		int b;

	public:
		int as;
		int bs;
		int cs;

};



int main(){

	double vFloat1 = 22.0 / 7;
	
	cout << vFloat1;
	
	cout << "Size of char is " << sizeof(char) << "bytes.\n";

	cout << "Size of int is " << sizeof(int) << "bytes.\n";

	cout << "Size of double is " << sizeof(vFloat1) << "bytes.\n";

	cout << "Size of class (with varaible int ,int ,int ,int ,int) A is "<< sizeof(A) << "bytes.\n";

	return 0;
}