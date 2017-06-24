class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums;
        sums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (sums[i - 1] < 0)
                sums.push_back(nums[i]);
            else
                sums.push_back(sums[i - 1] + nums[i]);
        }
        int res = sums[0];
        for (int i = 1; i < sums.size(); i++) {
            if (sums[i] > res)
                res = sums[i];
        }
        return res;
    }
};

/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() < 0)
            return 0;
        int res = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            if (sum > res)
                res = sum;
        }
        return res;
    }
};
*/