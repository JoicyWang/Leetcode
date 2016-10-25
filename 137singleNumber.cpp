class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for (auto num : nums) {
            int tmp = two;
            two = (one & num) | (two & (~num));
            one ^= num;
            one &= ~tmp;
        }
        return one;
    }
};