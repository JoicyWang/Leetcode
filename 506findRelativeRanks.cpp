class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int, std::greater<int>> order;
        for (int i = 0; i < nums.size(); i++) {
            order.insert(pair<int, int>(nums[i], i));
        }
        vector<string> solution(nums.size(), "");
        int i = 1;
        for (auto it = order.begin(); it != order.end(); it++, i++) {
            switch (i) {
                case 1:
                    solution[it->second] = "Gold Medal";
                    break;
                case 2:
                    solution[it->second] = "Silver Medal";
                    break;
                case 3:
                    solution[it->second] = "Bronze Medal";
                    break;
                default:
                    solution[it->second] = std::to_string(i);
                    break;
            }
        }
        return solution;
    }
    
};