#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() == 0)
            return b;
        if (b.size() == 0)
            return a;
        int minlen = min(a.size(), b.size());
        int maxlen = max(a.size(), b.size());
        string result((maxlen-minlen), '0');
        if (a.size() > b.size())
            b = result + b;
        else
            a = result + a;
        int flag = 0;
        result.resize(maxlen, '0');
        for (int i = maxlen - 1; i >= 0; i--) {
            int res = (a[i] - '0') + (b[i] - '0') + flag;
            if (res == 0) {
                result[i] = '0';
                flag = 0;
            }
            else if (res == 1) {
                result[i] = '1';
                flag = 0;
            }
            else if (res == 2) {
                result[i] = '0';
                flag = 1;
            }
            else {
                result[i] = '1';
                flag = 1;
            }
        }
        if (flag == 1) {
            result = '1' + result;
        }
        return result;
    }
};