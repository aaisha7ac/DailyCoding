class Solution {

    // 1.Recursion
    // TC : O(2^n)
    // SC : O(n), auxiliary stack space

public:

    int solve(int ind,int transNo,int k,int n,vector<int>& prices) {

        if(ind == n || transNo == 2 * k) {
            return 0;
        }

        if(transNo % 2 == 0) {
            return max(-prices[ind] + solve(ind+1,transNo + 1,k,n,prices),0 + solve(ind+1,transNo,k,n,prices));
        }

        return max(prices[ind] + solve(ind+1,transNo + 1,k,n,prices),0 + solve(ind+1,transNo,k,n,prices));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(0,0,k,n,prices);
    }
};

class Solution {

    // 2.Memoization
    // TC : O(ind * transNo)
    // SC : O(ind * transNo) + O(n), auxiliary stack space

public:

    int solve(int ind,int transNo,int k,int n,vector<int>& prices,vector<vector<int>> &dp) {

        if(ind == n || transNo == 2 * k) {
            return 0;
        }

        if(dp[ind][transNo] != -1) {
            return dp[ind][transNo];
        }

        if(transNo % 2 == 0) {
            return dp[ind][transNo] = max(-prices[ind] + solve(ind+1,transNo + 1,k,n,prices,dp),0 + solve(ind+1,transNo,k,n,prices,dp));
        }

        return dp[ind][transNo] = max(prices[ind] + solve(ind+1,transNo + 1,k,n,prices,dp),0 + solve(ind+1,transNo,k,n,prices,dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        return solve(0,0,k,n,prices,dp);
    }
};


class Solution {

    // 3.Tabulation
    // TC : O(ind * transNo)
    // SC : O(ind * transNo)

public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int transNo = 2*k - 1; transNo >= 0; transNo--) {
                if(transNo % 2 == 0) {
                    dp[ind][transNo] = max(-prices[ind] + dp[ind+1][transNo + 1],0 + dp[ind+1][transNo]);
                }
                else {
                    dp[ind][transNo] = max(prices[ind] + dp[ind+1][transNo + 1],0 + dp[ind+1][transNo]);
                }
            }
        }
       
        return dp[0][0];
    }
};


class Solution {

    // 4.Space optimization
    // TC : O(ind * transNo)
    // SC : O(transNo)
    
public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        vector<int>ahead(2*k+1,0),curr(2*k+1,0);

            for(int ind = n - 1; ind >= 0; ind--) {
                for(int transNo = 2*k - 1; transNo >= 0; transNo--) {
                    if(transNo % 2 == 0) {
                        curr[transNo] = max(-prices[ind] + ahead[transNo + 1],0 + ahead[transNo]);
                    }
                    else {
                        curr[transNo] = max(prices[ind] + ahead[transNo + 1],0 + ahead[transNo]);
                    }
                }
                ahead = curr;
            }
        
            return ahead[0];
    }
};