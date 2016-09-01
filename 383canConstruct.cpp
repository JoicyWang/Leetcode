#include <stdint.h>
#include <iostream>
#include <undered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> tmp;
        for (int i = 0; i < magazine.size(); i++) {
            if (tmp.find(magazine[i]) == tmp.end())
                tmp.insert({magazine[i], 1});
            else
                tmp[magazine[i]]++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (tmp.find(ransomNote[i]) == tmp.end())
                return false;
            else if (tmp[ransomNote[i]] == 1)
                tmp.erase(ransomNote[i]);
            else
                tmp[ransomNote[i]]--;
        }
        return true;
    }
};