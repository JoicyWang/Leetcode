#include <stdint.h>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> result;
		unordered_map<int, int> newNums;
		for (int i = 0; i < nums1.size(); i++) {
			if (newNums.find(nums1[i]) == newNums.end())
				newNums.insert({ nums1[i], 1 });
			else
				newNums[nums1[i]]++;
		}
		for (int i = 0; i < nums2.size(); i++) {
			if (newNums.find(nums2[i]) != newNums.end()) {
				result.push_back(nums2[i]);
				if (newNums[nums2[i]] > 1)
					newNums[nums2[i]]--;
				else
					newNums.erase(nums2[i]);
			}
		}
		return result;
	}
};