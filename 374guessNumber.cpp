#include <stdint.h>
#include <iostream>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int beg = 1, end = n;
        while (beg <= end) {
            int result = beg + (end - beg) / 2;
            if (guess(result) == 1) {
                beg = result + 1;
            }
            else if (guess(result) == -1){
                end = result - 1;
            }
            else
                return result;
        }
        return -1;
    }
};