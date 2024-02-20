class Solution {

    // 1.Memoization
    // TC : O(n * target)
    // SC : O(n * target) + O(n)
    
 
public:

    int solve(vector<int>& coins, int target,int n,vector<vector<int>> &dp) {

        // base case
        if(n == 0) {
            if(target % coins[n] == 0) {
                return target / coins[n];
            }
            else {
                return 1e9; // to prevent overflow
            }
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        int notpick = 0 + solve(coins,target,n-1,dp);

        int pick = INT_MAX;

        if(coins[n] <= target) {
            pick = 1 + solve(coins,target-coins[n],n,dp); // we can pick same coins for infinite times
        }

        return dp[n][target] = min(notpick,pick);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans = solve(coins,amount,n-1,dp);
        
        if(ans == 1e9) {
            return -1;
        }
        return ans;
        
    }
};


class Solution {

    // 1. Tabulation
    // TC : O(n * target)
    // SC : O(n * target)

 
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        // base case
        for(int c = 0; c <= amount; c++) {
             if(c % coins[0] == 0) {
                dp[0][c] = c / coins[0];
            }
            else {
                dp[0][c] = 1e9; // to prevent overflow
            }
        }


        for(int i = 1; i < n; i++) {
            for(int c = 0; c <= amount; c++) {
                int notpick = 0 + dp[i-1][c];

                int pick = INT_MAX;

                if(coins[i] <= c) {
                    pick = 1 + dp[i][c - coins[i]]; // we can pick same coins for infinite times
                }

                dp[i][c] = min(notpick,pick);
            }
        }

        int ans = dp[n-1][amount];
        
        if(ans == 1e9) {
            return -1;
        }
        return ans;
        
    }
};

class Solution {

    // 1. Space optimization
    // TC : O(n * target)
    // SC : O(target)

public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

       vector<int>prev(amount+1,0),curr(amount+1,0);

        // base case
        for(int c = 0; c <= amount; c++) {
             if(c % coins[0] == 0) {
                prev[c] = c / coins[0];
            }
            else {
                prev[c] = 1e9; // to prevent overflow
            }
        }


        for(int i = 1; i < n; i++) {
            for(int c = 0; c <= amount; c++) {
                int notpick = 0 + prev[c];

                int pick = INT_MAX;

                if(coins[i] <= c) {
                    pick = 1 + curr[c - coins[i]]; // we can pick same coins for infinite times
                }

                curr[c] = min(notpick,pick);
            }

            prev = curr;
        }

        int ans = prev[amount];
        
        if(ans == 1e9) {
            return -1;
        }
        return ans;
        
    }
};