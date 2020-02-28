#include <iostream>
using namespace std;

int main(){

  cout << "Enter the value of A, B and C:" << endl;

  int A=0,B=0,C=0;

  cin >> A >> B >> C;

  if(A <= 0||B<=0||C<=0||(A+B)<=C || (A+C) <= B || (B+C)<=A){
    cout << "Impossible";
  }else if (A==B && B==C){

        cout << "Equilateral";


  }else if (A==B || B==C ||C==B){
    cout << "Isosceles";
  }else {
    cout << "Scalene";
  }

  return 0;

}
