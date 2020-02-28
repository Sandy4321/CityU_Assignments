#include <iostream>
#include <string.h>
using namespace std;

char* replace(char *s)
{
    int len = strlen(s);
    int count = 0;
    char *p = s;
    while (*p != '\0')
    {
        if (*p == ' ')
        	count++;
        p++;
    }
    int n = len + count + 1;
    char *str = new char[n];
    char *ret = str;
    memset(str,'\0',n); // Set all chars in str to '\0'
	for (int i = 0; i < len; i++)
		str[i] = s[i];

    p = str + n - 1;
    char *q = str + len;
    while (q < p)
    {
        if (*q == ' ')
        {
            *p-- = '0';
            *p = '%';
        }
        else
        {
            *p = *q;
        }
        q--;
        p--;
    }
    return ret; 
}
int main()
{
    char s[50];
    cout << "Enter the input string: ";
    cin.getline(s, 50);
    
	cout << "The replace string is: " << replace(s);
	cout<< endl;

    return 0;
}