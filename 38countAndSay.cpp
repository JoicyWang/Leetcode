#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        string cur = countAndSay(n - 1);
        string res = "";
        for (int i = 0; i < cur.size(); i++) {
            int c = 1;
            while ((i < cur.size() - 1) && (cur[i] == cur[i + 1])) {
                c++;
                i++;
            }
            res += to_string(c) + cur[i];
        }
        return res;
    }
};