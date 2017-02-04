class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int rsize = board.size();
        int csize = board[0].size();
        int res = 0;
        for (int i = 0; i < rsize; i++) {
            for (int j = 0; j < csize; j++) {
                if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
                    res++;
            }
        }
        return res;
    }
};