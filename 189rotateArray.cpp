#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (k <= 0 || nums.size() <= 1)
			return;
		k %= nums.size();
		reverse(nums.begin(), nums.begin() + nums.size() - k);
		reverse(nums.end() - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};