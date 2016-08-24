#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        if (rowIndex < 1) {
            return res;
        }
        res.push_back(1);
        for (int i = 1; i < rowIndex; i++) {
            res.push_back(1);
            for (int j = i; j > 0; j--) {
                res[j] = res[j] + res[j - 1];
            }
        }
        return res;
    }
};