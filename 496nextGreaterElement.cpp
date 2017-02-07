class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> t;
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                t[nums[stk.top()]] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        int n = findNums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            auto it = t.find(findNums[i]);
            res[i] = it == t.end() ? -1 : it->second;
        }
        return res;
    }
};