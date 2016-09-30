#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long res = 0;
        string::const_iterator it = str.begin();
        while (it != str.end() && *it == ' ') it++;
        bool is_negative = false;
        if (*it == '+' || *it == '-') {
            is_negative = (*it == '-');
            it++;
        }
        while (it != str.end() && isDigit(*it)) {
            res *= 10;
            res += (*it) - '0';
            it++;
            if (!is_negative && res >= INT_MAX) return INT_MAX;
            else if (is_negative && -1 * res <= INT_MIN) return INT_MIN;
        }
        res = is_negative ? (-1 * res) : res;
        return res;
    }
private:
    bool isDigit (char c) {
        return c >= '0' && c <= '9';
    }
};