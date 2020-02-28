
#include <iostream>
using namespace std;

char *mystrncat(char *destination, const char *source, int num)
{
	// obtain the length of the destination
	int index = -1;
	while (destination[++index] != '\0')
	{
	}

	while (num > 0)
	{
		destination[index + num - 1] = source[num - 1];
		num--;
	}

	// if num is less than source length
	return destination;
}

char *mystrtok(char *str, const char *delimiters)
{
	// to keep the remainder
	static char strRemain[100];

	// testing to identify wherther strRemain is empty
	int index = 0;
	while (strRemain[index++] != '\0')
	{
		// cout << (strRemain[index] == '\0');
		
	}
	// cout << ;

	if (index> 1)
	{
		// cout << index;

		for (int reassign = 0; reassign < 100 && strRemain[reassign] != '\0'; reassign++)
		{
			str[reassign] = strRemain[reassign];
		}
	}

	bool found = false;

	for (int index = 0; index < 100 && str[index] != '\0'; index++)
	{
		for (int dIndex = 0; dIndex < 100 && delimiters[dIndex] != '\0'; dIndex++)
		{
			if (str[index] == delimiters[dIndex])
			{
				int remainIndex = 0;
				for (; remainIndex < 100 && str[remainIndex + index + 1] != '\0'; remainIndex++)
				{
					strRemain[remainIndex] = str[remainIndex + index + 1];
				}
				strRemain[remainIndex] = '\0';
				// cout << strRemain;
				str[index] = '\0';
				found = true;
				break;
			}
		}
		if (found)
		{
			break;
		}
	}

	return str;

	// int index = 0;

	// if (str != NULL){
	// 	int index= 0;
	// 	for (; index <100 && str[index]!= '\0';index++){
	// 		strRemain[index] = str[index];
	// 	}
	// 	strRemain[index] = '\0';
	// }

	// // int index=0;
	// bool found = false;
	// for (; index < 100  && strRemain[index] != '\0';index ++){
	// 	for (int delimitersIndex= 0 ; delimitersIndex<100 && delimiters[delimitersIndex]!='\0';delimitersIndex++){
	// 		if (strRemain[index] == delimiters[delimitersIndex]){
	// 			found = true;
	// 			break;
	// 		}

	// 	}
	// 	if(found){
	// 		break;
	// 	}

	// }

	// // if (str != NULL){
	// // 	str[index]='\0';
	// // 	int remainIndex = 0;
	// // 	for (remainIndex =index+1; remainIndex < 100 && strRemain[remainIndex] !='\0';remainIndex++){
	// // 		strRemain[remainIndex-index+1] = strRemain[remainIndex];
	// // 	}
	// // 	strRemain[remainIndex] ='\0';
	// // 	return str;
	// // }else{
	// // 	strRemain[index];
	// // }

	// return strRemain;
}

char *mystrcmp(const char *str1, const char *str2, char *result)
{
}

int main()
{
	// cout << "Input the destination:" << endl;
	// char destination[200];
	// cin.getline(destination, 100);

	// cout << "Input the source:" << endl;
	// char source[100];
	// cin.getline(source, 100);

	// cout << "Input the number of characters to be appended:" << endl;
	// int num;
	// cin >> num;

	// cout << "The concatenated resulting string is:" << endl;
	// cout << mystrncat(destination, source, num) << endl;

	cout << "Input a sentence:" << endl;
	char str[100];
	cin.getline(str, 100);

	cout << "Input the delimiters:" << endl;
	char delimiters[100];
	cin.getline(delimiters, 100);

	cout << "The tokens are:" << endl;

	bool isEmpty = false;
	while (!isEmpty){
		cout << mystrtok(str, delimiters) << endl;
		if (strlen(str)<=1){
			isEmpty =true;
		}
	}
	
	// cout << mystrtok(str, delimiters);

	// cout << mystrtok(NULL,delimiters);
	// cout << mystrtok(NULL,delimiters);
}
