#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		unordered_set<int> newNums;
		for (int i = 0; i < nums.size(); i++)
		{
			if (newNums.find(nums[i]) != newNums.end())
				return true;
			newNums.insert(nums[i]);
		}
		return false;
	}
};