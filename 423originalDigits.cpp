class Solution {
public:
    string originalDigits(string s) {
        vector<string> nums = {"zero", "six", "seven", "eight", "five", "four", "two", "three", "nine", "one"};
        string unique = "zxsgvuwtio";
        vector<int> digits = {0, 6, 7, 8, 5, 4, 2, 3, 9, 1};
        vector<int> c(10, 0);
        string res = "";
        vector<int> m(26, 0);
        for (char ch : s) {
            ++m[ch - 'a'];
        }
        for (int n = 0; n < nums.size(); ++n) {
            int count = c[digits[n]] = m[unique[n] - 'a'];
            for (auto ch : nums[n]) {
                m[ch - 'a'] -= count;
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int k = 0; k < c[i]; ++k) {
                res += to_string(i);
            }
        }
        return res;
    }
};