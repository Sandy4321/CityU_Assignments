#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib> // random
#include <ctime>
#include <climits>	// all useful constants
#include <functional> // for hash
#include <algorithm>
#include <sstream>
#include <iomanip>
// #include <regex>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*** Data Structure ***/
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <deque> // double ended queue
#include <list>  // priority queue
#include <map>
#include <set>
// using namespace std;
#define ull unsigned long long
#define DUBUG true
#define $(x) {if (DUBUG) std::cout << #x << " = " << x << " " << "\n";}
#define _(x) {if (DUBUG) std::cout << #x << " = " << x << " ";}

#define INF 0x3f3f3f3f
#define INF2 0x7fffffff
#define NEGINF 0x80000000

#define input(x) scanf("%d",&x)
#define inputs(x) scanf("%s",x)
#define output(x) printf("%d",x)
#define outputs(x) printf("%s", x)
#define lnBrk() printf("\n")

#define from(i, x, y) for (int i = x; i < y; ++i)
#define fromNeg(i, x, y) for (int i = x; i >= y; --i)

#define eps 1e-6

using namespace std;


void computeLPSArray(char* pat, int M, int* lps);
int maxFound = 0;
int maxFoundLen = 0;
int found = 0;
string maxFoundS;
// Prints occurrences of pat[] in txt[] 
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int* lps = new int[M];

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			//printf("Found pattern at index %d ", i - j);
			found++;
			j = lps[j - 1];
		}

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix 
	int len = 0;

	lps[0] = 0; // lps[0] is always 0 

				// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len]) 
		{
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment 
				// i here 
			}
			else // if (len == 0) 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}


int T;

void mainFunction()
{
	input(T);
	char s1[1001];
	char s2[1001];
	char maxFoundCS[1001];
	int s[1001][1001];
	while (T--) {
		inputs(s1);
		maxFound = 0;
		maxFoundLen = 0;
		bool foundAnything = false;
		// cout << s1 << endl;
		int strlens = strlen(s1);
		from(i,0,strlens){
			if ( s1[i] == s1[strlens-1] ) {
				s[i][strlens-1] = 1;
			}else{
				s[i][strlens-1] = 0;
			}
		}

		fromNeg(i,strlens-2,0){
			fromNeg(j,strlens-2,i+1){
				if (s1[i] == s1[j]){
					s[i][j] = s[i+1][j+1]+1;
					
				}else{
					s[i][j] = 0;
				}
			}
		}

		// from(i,0,strlens-1){
		// 	from(j,0,i+1){
		// 		cout << "  ";
		// 	}
		// 	from(j,i+1,strlens){
		// 		cout << s[i][j]<<" ";
		// 	}
		// 	cout << endl;
		// }


		maxFound = 0;
		maxFoundLen = 0;
		maxFoundCS[0] = '\0';
		bool foundInPast = false;
		from(i,0,strlens -1){
			foundInPast = true;
			from(j,i+1,strlens){
				if (s[i][j] > maxFoundLen){
					maxFoundLen = s[i][j];
					foundInPast = false;
					maxFound =1;
					int tempL = 0;
					from(k,i,maxFoundLen+i){
						maxFoundCS[tempL++] = s1[k];
					}
					maxFoundCS[tempL] = '\0';
				}else if (maxFoundLen == s[i][j]){
					// check inner details
					int tempL = 0;
						from(k,i,s[i][j]+i){
							s2[tempL++] = s1[k];
						}
					s2[tempL] = '\0';
					int compareRes = strcmp(s2,maxFoundCS);
					if (compareRes < 0){
						maxFoundLen = s[i][j];
						foundInPast = false;
						maxFound =1;
						tempL = 0;
						from(k,i,maxFoundLen+i){
							maxFoundCS[tempL++] = s1[k];
						}
						maxFoundCS[tempL] = '\0';
					}else if (compareRes == 0 && !foundInPast){
						maxFound++;
					}
				}
			}
		}



		if (maxFoundLen > 0) {

			cout << maxFoundCS << " " << maxFound+1 << '\n';
		}
		else {
			cout << "No repetitions found!\n";
		}
	}
}

int main()
{

	if (getenv("vscode") != NULL)
	{
		freopen("in.txt", "r", stdin);
	}
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	// testCaseGenerator();
	mainFunction();
	return 0;
}

/*
6
GATTACA
GAGAGAG
GATTACAGATTACA
TGAC
TGTAC
TTGGAACC
*/