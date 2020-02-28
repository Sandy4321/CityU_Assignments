#include <iostream>
using namespace std;

int countChar(char arr1[], char arr2[]){
	int cnt1, cnt2, i, count = 0;
	bool found;
	cnt1 = -1;
	cnt2 = -1;
	i = 0;
	while (arr1[i] != '\0'){
		cnt1++;
		i++;
	}
	i = 0;
	while (arr2[i] != '\0'){
		cnt2++;
		i++;
	}
	for(i = cnt1; i >= cnt2 ; i--){       // Traverse arr1 from end to start;
		if(arr1[i] == arr2[cnt2]){
			found = true;
			for(int j = 1 ; j <= cnt2 ; j++)
				if(arr1[i-j] != arr2[cnt2-j])
					found = false;
			if(found)
				count++;
		}
	}

	return count;


}

int main(){
	cout << "Enter two strings: ";
	char arr1[50], arr2[50];
	cin >> arr1 >> arr2;

	cout << "The occurrence of " << arr2 << " in " << arr1 << " is: " << countChar(arr1,arr2);
	return 0;
}