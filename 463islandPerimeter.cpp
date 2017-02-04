class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0, repeat = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                    if (i != 0 && grid[i - 1][j] == 1) repeat++;
                    if (j != 0 && grid[i][j - 1] == 1) repeat++;
                }
            }
        }
        return count * 4 - repeat * 2;
    }
};
/*
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) res += get_perimeter(grid, i, j);
            }
        }
        return res;
    }
    int get_perimeter(vector<vector<int>>& grid, int r, int c) {
        int cnt = 0;
        if (r - 1 < 0 || grid[r - 1][c] == 0) cnt++;
        if (r + 1 >= grid.size() || grid[r + 1][c] == 0) cnt++;
        if (c - 1 < 0 || grid[r][c - 1] == 0) cnt++;
        if (c + 1 >= grid[0].size() || grid[r][c + 1] == 0) cnt++;
        return cnt;
    }
};*/