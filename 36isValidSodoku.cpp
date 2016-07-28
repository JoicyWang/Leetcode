#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkValid(int vec[], int val) {
        if (val < 1)
            return true;
        if (vec[val - 1] == 1)
            return false;
        vec[val - 1] = 1;
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowValid[9] = {0};
        int columnValid[9] = {0};
        int subBoardValid[9] = {0};
        for (int i = 0; i < 9; i++) {
            memset(rowValid, 0, sizeof(rowValid));
            memset(columnValid, 0, sizeof(columnValid));
            memset(subBoardValid, 0, sizeof(subBoardValid));
            for (int j = 0; j < 9; j++) {
                if (!checkValid(rowValid, board[i][j] - '0') ||
                    !checkValid(columnValid, board[j][i] - '0') ||
                    !checkValid(subBoardValid, board[(i/3)*3 + j/3][(i%3)*3 + j%3] - '0'))
                    return false;
            }
        }
        return true;
    }
};