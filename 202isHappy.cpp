#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isHappy(int n)
	{
		if (n < 1)
			return false;
		else if (n == 1)
			return true;
		unordered_set<int> showedNums;
		showedNums.insert(n);
		while (true)
		{
			int s = 0;
			while (n)
			{
				s += pow(n % 10, 2);
				n = n / 10;
			}
			if (s == 1)
				return true;
			else if (showedNums.find(s) != showedNums.end())
				return false;
			n = s;
			showedNums.insert(s);
		}
	}
};