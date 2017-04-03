class Solution {
public:
    string decodeString(string s, int& i) {
        if (s.size() == 0) return "";
        string res = "";
        string tmp = "";
        while (i < s.size() && s[i] != ']') {
            if (s[i] >= '0' && s[i] <= '9') {
                int times = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    times = times * 10 + s[i] - '0';
                    i++;
                }
                i++;
                tmp = decodeString(s, i);
                i++;
                while (times-- > 0)
                    res += tmp;
            }
            else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};

/*
class Solution {
public:
    string parse(string s) {
        string r = "";
        for(int i = 0; i < s.size();) {
            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                int bracket_match = 1;
                int j = i;
                while(bracket_match > 0) {
                    ++j;
                    if(s[j] == '[') ++bracket_match;
                    else if(s[j] == ']') --bracket_match;
                }
                string temp = parse(s.substr(i + 1, j - i - 1));
                for(int k = 0; k < num; ++k) {
                    r += temp;
                }
                i = j + 1;
            } else if(isalpha(s[i])) {
                r += s[i];
                ++i;
            }
        }
        return r;
    }
    string decodeString(string s) {
        return parse(s);
    }
};
*/