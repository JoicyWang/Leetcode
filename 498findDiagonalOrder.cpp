class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for (int i = 0; i < n + m - 1; i++) {
            if (i % 2) {
                int y = min(i, m - 1), x = i - y;
                // down
                while (x < n && y >= 0) {
                    res.push_back(matrix[x][y]);
                    x++, y--;
                }
            } else {
                int x = min(i, n - 1), y = i - x;
                // up 
                while (x >= 0 && y < m) {
                    res.push_back(matrix[x][y]);
                    x--, y++;
                }
            }
        }
        return res;
    }
};