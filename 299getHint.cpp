#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int tmp[10] = {0};
        int size = secret.size();
        int a = 0, b = 0, s, g;
        for (int i = 0; i < size; i++) {
            if (guess[i] == secret[i]) {
                a++;
            }
            else {
                s = secret[i] - '0';
                g = guess[i]- '0';
                if (tmp[s] < 0)
                    b++;
                tmp[s]++;
                if (tmp[g] > 0)
                    b++;
                tmp[g]--;
            }
        }
        string res = int2Str(a) + 'A' + int2Str(b) + 'B';
        return res;
    }
private:
    string int2Str(int val) {
        ostringstream s;
        s << val;
        return s.str();
    }
};