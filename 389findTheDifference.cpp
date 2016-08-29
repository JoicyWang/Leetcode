#include <stdint.h>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> tmp;
        for (int i = 0; i < s.size(); i++) {
            if (tmp.find(s[i]) == tmp.end())
                tmp.insert({s[i], 1});
            else
                tmp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (tmp.find(t[i]) == tmp.end())
                return t[i];
            else if (tmp[t[i]] != 1)
                tmp[t[i]]--;
            else
                tmp.erase(t[i]);
        }
        return 0;
    }
};