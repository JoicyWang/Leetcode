#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int num;
        char tmp;
        string res = "";
        while (n) {
            num = (n - 1) % 26;
            tmp = num + 'A';
            res = tmp + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};