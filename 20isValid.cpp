class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') left.push(s[i]);
            else if (left.empty() || s[i] - left.top() > 2) return false;
            else left.pop();
        }
        return left.empty();
    }
};