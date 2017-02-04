class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 0, tmp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) tmp++;
            else if (res < tmp) {
                res = tmp;
                tmp = 0;
            }
            else tmp = 0;
        }
        if (res < tmp) res = tmp;
        return res;
    }
};