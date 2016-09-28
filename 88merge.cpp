#include <stdint.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, p = m + n - 1;
        while ((i >= 0) && (j >= 0)) {
            nums1[i] > nums2[j] ? nums1[p--] = nums1[i--] : nums1[p--] = nums2[j--];
        }
        while (i >= 0)
            nums1[p--] = nums1[i--];
        while (j >= 0)
            nums1[p--] = nums2[j--];
    }
};