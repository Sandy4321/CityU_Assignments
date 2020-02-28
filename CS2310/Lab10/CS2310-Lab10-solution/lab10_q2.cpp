#include <iostream>
using namespace std;

void getNameAndId(char arr[]){
	int cnt = -1;
	int i = 0;
	int IndexOfLastSpace;
	while(arr[i] != '\0'){
		cnt++;
		i++;
	}
	for(i = cnt; i >= 0; i--)
		if(arr[i] == ' '){
			IndexOfLastSpace = i;
			break;			
		}

	char id[50], name[50];
	for(i = 1; i <= cnt - IndexOfLastSpace; i++)
		id[i-1] = arr[IndexOfLastSpace + i];
	id[i] = '\0';
	for(i = 0; i < IndexOfLastSpace; i++)
		name[i] = arr[i];
	name[i] = '\0';
	cout << "Student name is: " << name << endl;
	cout << "Student ID is: " << id << endl;



}

int main(){
	cout << "Enter the student info: ";
	char arr[50];
	cin.getline(arr, 50);

	getNameAndId(arr);
	return 0;
}

