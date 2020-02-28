#include <iostream>
using namespace std;
int main (){
    int num;
    cout << "Enter a positive integer less than 100: ";
    cin >> num;
    int sum;
    do {
		sum = 0;
        if (num >= 100 ){
            sum += 1;
            num -= 100;//since the maximum is 99 = 81+81 = 162
        }
        sum += ( num / 10 ) * ( num / 10 );
        sum += ( num % 10 ) * ( num % 10 ); 
        
        num = sum;
		cout << num << ' ';
    }while (num != 1 && num != 4);

    if (num == 1){
        cout << endl << "This is a happy number." << endl;
    }else {
        cout << endl << "This is an unhappy number." << endl;
    }
    return 0;
}