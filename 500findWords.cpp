class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int index[] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        vector<string> res;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() == 0) continue;
            int tmp = index[findIndex(words[i][0])];
            bool is = true;
            for (int j = 1; j < words[i].size(); j++) {
                if (index[findIndex(words[i][j])] != tmp) {
                    is = false;
                    break;
                }
            }
            if (is) res.push_back(words[i]);
        }
        return res;
    }
    int findIndex(char tmp) {
        if (tmp >= 'a' && tmp <= 'z') return tmp - 'a';
        else return tmp - 'A';
    }
};