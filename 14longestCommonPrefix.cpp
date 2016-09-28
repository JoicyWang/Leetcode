#include <stdint.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];
        int r = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (strs[0][j] == strs[i][j]) j++;
            if (j < r) r = j;
        }
        string res = strs[0].substr(0, r);
        return res;
    }
};