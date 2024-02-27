class Solution {

    // 1.Recursion
    // TC : O(2^n)
    // SC : O(n)

public:

    int solve(int ind,int n,vector<int>& prices,int buy) {

        if(ind == n) {
            return 0;
        }

        if(buy) { // if buy == 1 we will buy
            return max(-prices[ind] + solve(ind+1,n,prices,0) , 0 + solve(ind+1,n,prices,1));
        }

        // if buy == 0 we will sell
        return max(prices[ind] + solve(ind+1,n,prices,1) , 0 + solve(ind+1,n,prices,0));
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return solve(0,n,prices,1);
        
    }
};

class Solution {

    // 2.Memoization
    // TC : O(ind * 2)   two values of buy 0 and 1
    // SC : O(ind * 2) + O(n)

public:

    int solve(int ind,int n,vector<int>& prices,int buy,vector<vector<int>> &dp) {

        if(ind == n) {
            return 0;
        }

        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        if(buy) { // if buy == 1 we will buy
            return dp[ind][buy] = max(-prices[ind] + solve(ind+1,n,prices,0,dp) , 0 + solve(ind+1,n,prices,1,dp));
        }

        // if buy == 0 we will sell
        return dp[ind][buy] = max(prices[ind] + solve(ind+1,n,prices,1,dp) , 0 + solve(ind+1,n,prices,0,dp));
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return solve(0,n,prices,1,dp);
        
    }
};

class Solution {

    // 3.Tabulation
    // TC : O(ind * 2)   two values of buy 0 and 1
    // SC : O(ind * 2)

public:

    // int solve(int ind,int n,vector<int>& prices,int buy,vector<vector<int>> &dp) {

    //     if(ind == n) {
    //         return 0;
    //     }

    //     if(dp[ind][buy] != -1) {
    //         return dp[ind][buy];
    //     }
    //     if(buy) { // if buy == 1 we will buy
    //         return dp[ind][buy] = max(-prices[ind] + solve(ind+1,n,prices,0,dp) , 0 + solve(ind+1,n,prices,1,dp));
    //     }

    //     // if buy == 0 we will sell
    //     return dp[ind][buy] = max(prices[ind] + solve(ind+1,n,prices,1,dp) , 0 + solve(ind+1,n,prices,0,dp));
    // }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {

                if(buy) { // if buy == 1 we will buy
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }

                // if buy == 0 we will sell
                else {
                    dp[ind][buy] = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }

            }
        }

        return dp[0][1];
        
    }
};

class Solution {

    // 4.Space optimization
    // TC : O(ind * 2)   two values of buy 0 and 1
    // SC : O(1)

public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<int>ahead(2,0),curr(2,0);

        ahead[0] = ahead[1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {

                if(buy) { // if buy == 1 we will buy
                    curr[buy] = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }

                // if buy == 0 we will sell
                else {
                    curr[buy] = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }

            }

            ahead = curr;
        }

        return ahead[1];
        
    }
};

