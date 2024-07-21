class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit =0;
        for(int i=1; i<prices.size(); i++){
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};