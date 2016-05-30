#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int temp = 1;
		vector<int> result = { temp };
		for (int i = 0; i < nums.size() - 1; i++)
		{
			temp = temp * nums[i];
			result.push_back(temp);
		}
		for (int i = nums.size() - 2; i > 0; i--)
		{
			nums[i] = nums[i + 1] * nums[i];
		}
		for (int i = 0; i < nums.size() - 1; i++)
		{
			result[i] = result[i] * nums[i + 1];
		}
		return result;
	}
};