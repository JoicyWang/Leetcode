#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.length() <= 0)
            return 0;
        int length = s.length() - 1;
        int sum = 0;
        while ((s[length] == ' ') && (length > 0))
            length--;
        for (int i = length; i >= 0; i--) {
            if (s[i] != ' ')
                sum++;
            else
                break;
        }
        return sum;
    }
};