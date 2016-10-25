class Solution {
private:
    void dfs(int k, int n, int level, vector<int>& tmp, vector<vector<int>>& res) {
        if (n < 0) return;
        if (n == 0 && tmp.size() == k) res.push_back(tmp);
        for (int i = level; i <= 9; i++) {
            tmp.push_back(i);
            dfs(k, n - i, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(k, n, 1, tmp, res);
        return res;
    }
};