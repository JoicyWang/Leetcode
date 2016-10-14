class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int pro = 0, buy = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] >= buy) {
                pro = pro + prices[i] - buy;
                buy = prices[i];
            }
            else {
                buy = prices[i];
            }
        }
        return pro;
    }
};