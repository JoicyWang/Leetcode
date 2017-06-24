class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> num;
        for (int i = 0; i < n; i++) {
            num.push_back(0);
        }
        for (int i = 0; i < n; i++) {
            num[nums[i] - 1] += 1;
        }
        for (int i = 0; i < n; i++) {
            if (num[i] > 1)
                res.push_back(i + 1);
        }
        return res;
    }
};