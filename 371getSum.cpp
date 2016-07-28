#include <stdint.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};