class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int res = 0;
        int *zeroOne = new int[2];
        int zeroCnt = 0;
        while (zeroCnt != size) {
            zeroCnt = 0;
            zeroOne[0] = 0;
            zeroOne[1] = 0;
            for (int i = 0; i < size; i++) {
                if (nums[i] == 0) zeroCnt++;
                zeroOne[nums[i] % 2]++;
                nums[i] = nums[i] >> 1;
            }
            res += zeroOne[0] * zeroOne[1];
        } 
        return res;
    }
};