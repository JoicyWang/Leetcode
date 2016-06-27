#include <stdint.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int take = 0, notake = 0, result = 0;
		for (int i = 0; i < nums.size(); i++) {
			take = notake + nums[i];
			notake = result;
			result = max(take, notake);
		}
		return result;
	}
};