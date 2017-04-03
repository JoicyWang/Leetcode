class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int res = 0, arrow = 0;
        sort(points.begin(), points.end(), newSort);
        for (int i = 0; i < points.size(); i++) {
            if (arrow != 0 && points[i].first <= arrow) continue;
            arrow = points[i].second;
            res++;
        }
        return res;
    }
    
    static bool newSort(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }
};