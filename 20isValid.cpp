#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> temp;
        if (s.length() % 2 != 0)
            return false;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
                temp.push_back(s[i]);
            else {
                if (temp.empty())
                    return false;
                else if ((s[i] == ')') && (*(temp.end() - 1) == '('))
                    temp.pop_back();
                else if ((s[i] == '}') && (*(temp.end() - 1) == '{'))
                    temp.pop_back();
                else if ((s[i] == ']') && (*(temp.end() - 1) == '['))
                    temp.pop_back();
                else
                    return false;
            }
        }
        if (temp.empty())
            return true;
        else
            return false;
    }
};