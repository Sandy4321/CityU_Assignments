#include <vector>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

bool comparator(int i, int j)
{
	return j < i;
}

struct ResultForSumCountTest
{
	vector<int> whichStick;
	bool feasible;
};

ResultForSumCountTest testStick(vector<int> sticks, int sumCount, int totalSum)
{
	int startIndex = 0;
	for (int i = 0; i < sticks.size(); i++)
	{
		if (totalSum < sticks[i])
		{
			startIndex++;
		}
	}

	bool *selected;
	selected = new bool[sticks.size()];
	while (sticks.size() - startIndex >= sumCount)
	{
		// cout << "Trying startIndex :"<<startIndex << endl;
		int i = startIndex;
		int currSumCount = 0;
		int currSum = 0;
		vector<int> sticksForSum;
		memset(selected, false, sizeof(selected));
		while (currSumCount < sumCount - 1 && i < sticks.size())
		{
			if (sticks[i] + currSum < totalSum)
			{
				sticksForSum.push_back(sticks[i]);
				currSum += sticks[i];
				currSumCount++;
				selected[i] = true;
			}
			i++;
		}

		// cout << "i: " << i <<" currSum : "<<currSum<<endl;
		// "i" will reach a place where the stick after "i" should be able to add to exactly totalSum
		for (int j = i; j < sticks.size(); j++)
		{
			if (!selected[j] && sticks[j] + currSum == totalSum)
			{
				sticksForSum.push_back(sticks[j]);
				currSum += sticks[i];
				ResultForSumCountTest res;
				res.feasible = true;
				res.whichStick = sticksForSum;
				return res;
			}
		}

		startIndex++;
	}
	ResultForSumCountTest res;
	res.feasible = false;
	return res;
}

ResultForSumCountTest getBigStick(vector<int> sticks, int totalSum)
{

	int sumCount = 1;
	while (sumCount <= sticks.size())
	{
		// cout << "trying to combine : " <<sumCount<<" of them " << endl;

		ResultForSumCountTest res = testStick(sticks, sumCount, totalSum);
		if (res.feasible)
		{
			return res;
		}
		sumCount++;
	}

	ResultForSumCountTest res;
	res.feasible = false;
	return res;
}

bool tryFormSquare(vector<int> sticks)
{
	int maxLength = 0;
	int tryLength = sticks[0];

	bool usingStick[sticks.size()];
	for (int i = 0; i < sticks.size(); i++)
	{
		maxLength += sticks[i];
		if (tryLength > sticks[i]){
			tryLength = sticks[i];
		}
	}
	maxLength /= 4;

	sort(sticks.begin(), sticks.end(), comparator);


	while (tryLength <= maxLength)
	{
		memset(usingStick, false, sizeof(usingStick));
	// cout <<"Trying "<< tryLength<< endl;
		for (int j = 0; j < 4; j++)
		{

			vector<int> remainingSticks;
			for (int i = 0; i < sticks.size(); i++)
			{
				if (!usingStick[i])
				{
					remainingSticks.push_back(sticks[i]);
				}
			}

			ResultForSumCountTest res = getBigStick(remainingSticks, tryLength);
			if (res.feasible)
			{
				if (j == 3)
				{
					return true;
				}
				else
				{
					for (int i = 0; i < res.whichStick.size(); i++)
					{
						for (int k = 0; k < sticks.size(); k++)
						{
							if (!usingStick[k] && res.whichStick[i] == sticks[k])
							{
								usingStick[k] = true;
								break;
							}
						}
					}
				}
			}
			else
			{
				break;
			}
		}

		tryLength++;
	}
	return false;
}

int main()
{

	int T;
	cin >> T;
	int i = 0;
	while (T--)
	{
		i ++;
		int n;
		cin >> n;
		vector<int> sticks;
		int tempStick;
		for (int i = 0; i < n; i++)
		{
			cin >> tempStick;
			sticks.push_back(tempStick);
		}
		cout << "Case #" << i <<": ";
		if (tryFormSquare(sticks))
		{
			cout << "yes";
		}
		else
		{
			cout << "no";
		}
		cout << endl;
		sticks.clear();
	}

	return 0;
}

90
50
40
90
10
20
40
10
1000
2000
9000
5000
4000
9000
1000
2000
7000
500
10000
2000