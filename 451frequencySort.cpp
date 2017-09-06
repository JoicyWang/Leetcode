class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        vector<int> bucket(256, 0);
        for (char c:s) {
            bucket[c]++;
        }
        vector<pair<int, char>> freq;
        for (int i = 0; i < 256; i++) {
            if (bucket[i] > 0)
                freq.push_back(make_pair(bucket[i], i));
        }
        sort(freq.begin(), freq.end());
        for (int i = freq.size() - 1; i >= 0; i--) {
            string tmp(freq[i].first, freq[i].second);
            res += tmp;
        }
        return res;
    }
};