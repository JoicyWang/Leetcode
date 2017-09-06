class Solution {
private:
    int winner (vector<int>& nums, int start, int end, int turn, int sum)
    {
        if (start == end)
        {
            return turn * nums[start] + sum; 
        }
        else
        {
            int res1 = winner(nums, start + 1, end, 0 - turn, sum + turn * nums[start]);
            int res2 = winner(nums, start, end - 1, 0 - turn, sum + turn * nums[end]);
            return turn * max(turn * res1, turn * res2);
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        return winner(nums, 0, nums.size() -1, 1, 0) >= 0;
    }
        bool PredictTheWinner0(vector<int>& nums) {
        if (nums.size() < 2)
            return true;
        int* dp = new int[nums.size()];
        for (int s = nums.size() - 1; s >= 0; s--) {
            for (int e = s + 1; e < nums.size(); e++) {
                int res1 = nums[s] - dp[e];
                int res2 = nums[e] - dp[e - 1];
                dp[e] = max(res1, res2);
            }
        }
        return dp[nums.size() - 1] >= 0;
    }
};