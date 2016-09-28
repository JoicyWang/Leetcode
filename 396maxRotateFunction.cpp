#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size(), sum = 0, f = 0;
        for (int i = 0; i < n; i++) {
            sum += A[i];
            f += i * A[i];
        }
        int res = f;
        for (int i = 1; i < n; i++) {
            f = f + sum - n * A[n - i];
            res = max(res, f);
        }
        return res;
    }
};