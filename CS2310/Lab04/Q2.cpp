#include <iostream>
#include <iomanip>
using namespace std;


int main(){




  int num,sum=0,l=0,s=0;
  cout << "Enter 4 interger values:" <<endl;
  cin >> num;
  if (num > l){
    l = num;
  }
  s=num;
  sum += num;
  cin >> num;
  if (num > l){
    l = num;
  }
  if (num < s){
    s = num;
  }
  sum += num;
  cin >> num;
  if (num > l){
    l = num;
  }
  if (num < s){
    s = num;
  }
  sum += num;
  cin >> num;
  if (num > l){
    l = num;
  }
  if (num < s){
    s = num;
  }
  sum += num;

  sum -= l + s;

  cout << sum << endl;
  cout << l << endl << s;
  int median = 0;

  cout << "The median of 4 values is :" << double(sum/2.0);
  return 0;



}
