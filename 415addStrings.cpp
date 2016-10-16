class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1, p2 = num2.size() - 1;
        if (p1 < p2) return addStrings(num2, num1);
        int n = 0, t = 0;
        while (p2 >= 0) {
            t = (num1[p1] - '0') + (num2[p2] - '0') + n;
            if (t > 9) {
                n = 1;
                t -= 10;
            }
            else n = 0;
            num1[p1] = t + '0';
            p1--;
            p2--;
        }
        while (p1 >= 0) {
            t = (num1[p1] - '0') + n;
            if (t > 9) {
                n = 1;
                t -= 10;
            }
            else n = 0;
            num1[p1] = t + '0';
            p1--;
        }
        if (n == 1) num1 = '1' + num1;
        return num1;
    }
};