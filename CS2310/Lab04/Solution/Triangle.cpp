#include<iostream>  

using namespace std;


int main() {
    int a, b, c;
    cout<<"Enter the value of A, B and C:"<<endl;
    cin >> a >> b >> c;
    if( a+ b <= c || a+c <=b || b+c<=a){
        cout << "Impossible"<<endl;
    }else if(a == b && b == c){
        cout<<"Equilateral"<<endl;
    }else if(a== b || b == c || a == c){
        cout<<"Isosceles"<<endl;
    }else{
        cout<<"Scalene"<<endl;
    }
    
    return 0;

}
//a b c d