#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_set<int> newNums;
		if (k == 0)
			return false;
		else if (k > nums.size()) {
			for (int i = 0; i < nums.size(); i++) {
				if (newNums.find(nums[i]) != newNums.end())
					return true;
				else
					newNums.insert(nums[i]);
			}
		}
		else
		{
			for (int i = 0; i < k; i++) {
				if (newNums.find(nums[i]) != newNums.end())
					return true;
				else
					newNums.insert(nums[i]);
			}
			for (int i = k; i < nums.size(); i++) {
				if (newNums.find(nums[i]) != newNums.end())
					return true;
				else {
					newNums.erase(nums[i - k]);
					newNums.insert(nums[i]);
				}
			}
		}
		return false;
	}
};