#include <iostream>
#include <cstring>
using namespace std;



void mergeStrings(char arr1[], char arr2[]){
	char arr3[100];
	int cnt = -1;
	int i = 0, j = 0;
	while(arr1[i] != '\0'){
		cnt++;
		i++;
	}
	//Sort two arrays first
	for (i = 0; i < cnt; i++){
		for (j = 0; j < cnt - i; j++){
			if (arr1[j] > arr1[j + 1]){
				char temp;
				temp = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = temp;
			}
		}
	}
	

	for (i = 0; i < cnt; i++){
		for (j = 0; j < cnt - i; j++){
			if (arr2[j] > arr2[j + 1]){
				char temp;
				temp = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = temp;
			}
		}
	}
	
	i = 0;
	j = 0;
	int count = 2 * cnt + 1;
	for(int k = 0; k <= count; k++){
		if(i == cnt + 1){
			arr3[k] = arr2[j];
			j++;
			continue;
		}
		if(j == cnt + 1){
			arr3[k] = arr1[i];
			i++;
			continue;
		}

		if(arr1[i] < arr2[j]){
			arr3[k] = arr1[i];
			i++;
		}
		else{
			arr3[k] = arr2[j];
			j++;
		}
	}
	arr3[count + 1] = '\0';
	cout << "Merged String: " << arr3 << endl;

}

int main(){
	char arr1[50], arr2[50], arr3[50];
	cout << "Input String 1: ";
	cin >> arr1;
	cout << "Input String 2: ";
	cin >> arr2;
	
	mergeStrings(arr1, arr2);

	return 0;
}