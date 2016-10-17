class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        for (int i = 0; i <= target; i++) {
            for (int k = 0; k < nums.size(); k++) {
                if (i - nums[k] > 0) dp[i] += dp[i - nums[k]];
                else if (i - nums[k] == 0) dp[i] += 1;
            }
        }
        return dp[target];
    }
};