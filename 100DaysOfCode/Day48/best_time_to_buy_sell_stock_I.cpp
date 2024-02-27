class Solution {

    // TC : O(n)
    // SC : O(1)
    

public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); i++) {
            profit = max(prices[i]-buy,profit);
            buy = min(buy,prices[i]);
        }

        return profit;
        
    }
};