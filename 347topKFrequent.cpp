class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++) {
            table[nums[i]]++;
        }
        vector<vector<int>> cnt(nums.size() + 1);
        for (auto p : table) {
            cnt[p.second].push_back(p.first);
        }
        vector<int> res;
        for (int i = cnt.size() - 1; i >= 0 && res.size() < k; i--) {
            for (auto n : cnt[i]) {
                res.push_back(n);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};