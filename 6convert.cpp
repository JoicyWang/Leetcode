#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res[numRows];
        int i = 0;
        while(i < s.size()) {
            for (int j = 0; (j < numRows) && (i < s.size()); j++) {
                res[j] += s[i++];
            }
            for (int j = numRows - 2; (j > 0) && (i < s.size()); j--) {
                res[j] += s[i++];
            }
        }
        string result = "";
        for (i = 0; i < numRows; i++) {
            if (res[i] != "")
                result += res[i];
        }
        return result;
    }
};