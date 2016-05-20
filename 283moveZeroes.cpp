#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums)
	{
		if (nums.empty() && nums.size() == 1)
			return;
		else
		{
			int i = 0, p = 0;
			while (i < nums.size())
			{
				if (nums[i] != 0)
				{
					nums[p++] = nums[i];
				}
				i++;
			}
			for (; p < nums.size(); p++)
				nums[p] = 0;
		}
	}
};