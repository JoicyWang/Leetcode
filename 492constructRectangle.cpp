class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = static_cast<int>(sqrt(area));
        vector<int> res;
        while (w > 0 && area % w) {
            w--;
        }
        int l = area / w;
        res.push_back(l);
        res.push_back(w);
        return res;
    }
};