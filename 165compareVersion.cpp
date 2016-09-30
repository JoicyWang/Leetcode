#include <stdint.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;
        while(version1.find('.') != std::string::npos) {
            v1.push_back(version1.substr(0, version1.find('.')));
            version1 = version1.substr(version1.find('.') + 1);
        }
        v1.push_back(version1);
        while (version2.find('.') != std::string::npos) {
            v2.push_back(version2.substr(0, version2.find('.')));
            version2 = version2.substr(version2.find('.') + 1);
        }
        v2.push_back(version2);
        int len = v1.size() >= v2.size() ? v1.size() : v2.size();
        if (v1.size() < len) {
            int dis = len - v1.size();
            for (int i = 0; i < dis; i++) v1.push_back("0");
        }
        if (v2.size() < len) {
            int dis = len - v2.size();
            for (int i = 0; i < dis; i++) v2.push_back("0");
        }
        for (int i = 0; i < len; i++) {
            if (stoi(v1[i]) > stoi(v2[i])) return 1;
            if (stoi(v1[i]) < stoi(v2[i])) return -1;
        }
        return 0;
    }
};