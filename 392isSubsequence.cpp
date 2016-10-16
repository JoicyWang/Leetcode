class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (ti <= t.size()) {
            if (si == s.size()) return true;
            if (s[si] == t[ti]) si++;
            ti++;
        }
        return false;
    }
};

/*
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ssize = s.size();
        int last = -1;
        size_t ind;
        for (int i = 0; i < ssize; i++) {
            ind = t.find(s[i], last + 1);
            if (ind == string::npos) return false;
            else {
                if (ind < max(0, last)) return false;
                last = ind;
            }
        }
        return true;
    }
};
*/