class Solution {

    // 1.Recursion
    // TC : O(2^n)
    // SC : O(n)
    
public:

    int solve(int ind,int buy,int n,vector<int>& prices) {

        if(ind >= n) {
            return 0;
        }

        if(buy) {
            return max(-prices[ind] + solve(ind + 1,0,n,prices), 0 + solve(ind + 1,1,n,prices));
        }

        return max(prices[ind] + solve(ind + 2,1,n,prices), 0 + solve(ind + 1,0,n,prices));
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        return solve(0,1,n,prices);
        
    }
};

class Solution {

    // 2.Memoization
    // TC : O(ind * 2)   two values of buy 0 and 1
    // SC : O(ind * 2) + O(n)


public:

    int solve(int ind,int buy,int n,vector<int>& prices,vector<vector<int>> &dp) {

        if(ind >= n) {
            return 0;
        }

        if(dp[ind][buy] != -1) {
            return dp[ind][buy];
        }
        if(buy) {
            return dp[ind][buy] =  max(-prices[ind] + solve(ind + 1,0,n,prices,dp), 0 + solve(ind + 1,1,n,prices,dp));
        }

        return dp[ind][buy] = max(prices[ind] + solve(ind + 2,1,n,prices,dp), 0 + solve(ind + 1,0,n,prices,dp));
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
        
    }
};

class Solution {

    // 3.Tabulation
    // TC : O(ind * 2)   two values of buy 0 and 1
    // SC : O(ind * 2)


public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        //dp[n][0] = dp[n][1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                if(buy) {
                    dp[ind][buy] =  max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                }
                else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
                }
            }
        }
        

        return dp[0][1];
        
    }
};

class Solution {

    // 4.Optimized
    // TC : O(ind)
    // SC : O(ind * 2)


public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));

        //dp[n][0] = dp[n][1] = 0;

        for(int ind = n - 1; ind >= 0; ind--) {

            dp[ind][1] =  max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                
            dp[ind][0] = max(prices[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
          
        }
        

        return dp[0][1];
        
    }
};