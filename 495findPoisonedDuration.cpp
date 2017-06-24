class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        int times = timeSeries.size();
        int cnt = 0;
        for (int i = 0; i < times; i++) {
            int tmp = timeSeries[i] + duration;
            if (tmp < cnt) {
                continue;
            } else if (timeSeries[i] < cnt) {
                res += tmp - cnt;
                cnt = tmp;
            } else {
                cnt = tmp;
                res += duration;
            }
        }
        return res;
    }
    int findPoisonedDuration1(vector<int>& timeSeries, int duration) {
        int times = timeSeries.size();
        if (times == 0) return 0;
        
        int res = 0;
        for (int i = 1; i < times; i++) {
            res += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        return res + duration;
    }
};