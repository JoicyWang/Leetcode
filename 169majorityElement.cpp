#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
public:
	int majorityElement1(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		int index = nums.size() / 2;
		return nums[index];
	}
	int majorityElement2(vector<int>& nums)
	{
		int result = 0, count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (count == 0)
			{
				result = nums[i];
				count++;
			}
			else
			{
				if (nums[i] == result)
					count++;
				else
					count--;
				if (count > nums.size() / 2 + 1)
					return result;
			}
		}
		return result;
	}
};