#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		if (prices.size() < 2)
			return 0;
		int maxPro = 0, curMin = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			curMin = min(curMin, prices[i]);
			maxPro = max(maxPro, prices[i] - curMin);
		}
		return maxPro;
	}
};