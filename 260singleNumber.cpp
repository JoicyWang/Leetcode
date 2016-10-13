class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXb = 0;
        for (int i = 0; i < nums.size(); i++) {
            aXb ^= nums[i];
        }
        int lastBit = (aXb & (aXb - 1)) ^ aXb;
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & lastBit) a = a ^ nums[i];
            else b = b ^ nums[i];
        }
        return vector<int> {a, b};
    }
};