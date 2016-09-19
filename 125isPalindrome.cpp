#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!check(s[i])) {
                i++;
                continue;
            }
            if (!check(s[j])) {
                j--;
                continue;
            }
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
private:
    bool check(char &c) {
        if ((c >= 'A') && (c <= 'Z')) {
            c = c - 'A' + 'a';
            return true;
        }
        return ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'));
    }
};