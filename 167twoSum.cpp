class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s= 0, f = numbers.size() - 1;
        int tmp = numbers[s] + numbers[f];
        vector<int> res;
        while (s < f && tmp != target) {
            if (tmp < target) s++;
            else f--;
            tmp = numbers[s] + numbers[f];
        }
        res.push_back(s + 1);
        res.push_back(f + 1);
        return res;
    }
};