class Solution {
private:
    vector<int> ori;
public:
    Solution(vector<int> nums) {
        ori = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = ori;
        for (int i = 0; i < res.size(); i++) {
            int t = rand() % res.size();
            swap(res[i], res[t]);
        }
        return res;
    }
};