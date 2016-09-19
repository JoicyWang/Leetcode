#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        len = nums.size();
        sum.push_back(nums[0]);
        for (int i = 1; i < len; i++)
            sum.push_back(sum[i - 1] + nums[i]);
    }

    int sumRange(int i, int j) {
        if ((j < i) || (i > len) || (j > len))
            return 0;
        else if (i == 0)
            return sum[j];
        return sum[j] - sum[i - 1];
    }
private:
    vector<int> sum;
    int len;
};