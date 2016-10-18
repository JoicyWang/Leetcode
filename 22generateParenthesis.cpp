class Solution {
private:
    void bt(int open, int close, const string& str, int n, vector<string>& res) {
        if (str.size() == n * 2) {
            res.push_back(str);
            return;
        }
        if (open > n - 1) bt(open, close + 1, str + ")", n, res);
        else if (open > close) {
            bt(open + 1, close, str + "(", n, res);
            bt(open, close + 1, str + ")", n, res);
        }
        else bt(open + 1, close, str + "(", n, res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str = "";
        bt(0, 0, str, n, res);
        return res;
    }
};