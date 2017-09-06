#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, res = 0, n = nums.size(), min = nums[0];
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (min > nums[i]) {
                min = nums[i];
            }
        }
        res = sum - min * n;
        return res;
    }
};