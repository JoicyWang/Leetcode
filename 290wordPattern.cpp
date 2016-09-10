#include <stdint.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int begin = 0, space = str.find(" ");
        if ((space == string::npos) && (pattern.size() == 1))
            return true;
        else if (space == string::npos)
            return false;
        unordered_map<char, string> tp;
        unordered_map<string, char> ts;
        for (int i = 0; i < pattern.size(); i++) {
            string word = str.substr(begin, space - begin);
            if ((ts[word] != pattern[i]) && (ts[word] != 0))
                return false;
            else if ((tp[pattern[i]] != word) && (tp[pattern[i]] != ""))
                return false;
            ts[word] = pattern[i];
            tp[pattern[i]] = word;
            begin = space + 1;
            space = str.find(" ", begin + 1);
        }
        space = str.find_last_of(" ");
        return begin > space && space != string::npos ? false : true;
    }
};