class Solution {
public:
    int findNthDigit(int n) {
        if (n < 1) return 0;
        if (n <= 9) return n;
        long b = 1, d = 1, res = 0;
        while (n - 9 * b * d > 0) {
            n -= 9 * b * d;
            d++;
            b *= 10;
        }
        res = (n + 1) / d + b - 1;
        n %= d;
        if (n == 0) n += d;
        for (int i = 0; i < d - n; i++) res /= 10;
        return res % 10;
    }
};