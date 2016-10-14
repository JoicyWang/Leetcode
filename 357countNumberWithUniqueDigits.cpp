class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, pro = 9, sum = 9;
        for (int i = 2; i <= n; i++) {
            sum *= pro;
            --pro;
            res += sum;
        }
        return res;
    }
};