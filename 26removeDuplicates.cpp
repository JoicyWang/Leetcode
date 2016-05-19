#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if (nums.empty())
			return 0;
		int length = 1, index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[index] != nums[i])
			{
				length++;
				nums[++index] = nums[i];
			}
		}
		return length;
	}
};