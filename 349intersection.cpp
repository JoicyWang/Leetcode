#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_set<int> nums;
		unordered_set<int> inter;
		vector<int> dup;
		for (auto i : nums1)
		{
			nums.insert(i);
		}
		for (auto i : nums2)
		{
			if ((nums.find(i) != nums.end()))
			{
				if (inter.count(i) == 0)
					dup.push_back(i);
				inter.insert(i);
			}
		}
		return dup;
	}
};