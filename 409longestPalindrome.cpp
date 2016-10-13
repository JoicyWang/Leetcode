class Solution {
private:
    int solve(int n[], int i, bool& isOdd) {
        if (n[i] % 2 == 0) return n[i];
        else {
            isOdd = true;
            return n[i] / 2 * 2;
        }
    }
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool isOdd = false;
        int lower[26] = {0}, upper[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') lower[s[i] - 'a']++;
            else upper[s[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            res += solve(lower, i, isOdd);
            res += solve(upper, i, isOdd);
        }
        if (isOdd) return res + 1;
        else return res;
    }
};