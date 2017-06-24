class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int children = 0, cookie = 0;
        int gNum = g.size(), sNum = s.size();
        int res = 0;
        while (children < gNum && cookie < sNum) {
            if (g[children] > s[cookie])
                cookie++;
            else {
                children++;
                cookie++;
                res++;
            }
        }
        return res;
    }
};