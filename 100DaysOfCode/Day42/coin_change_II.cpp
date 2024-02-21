class Solution {

    // 2.Memoization
    // TC : O(n * target)
    // SC : O(n * target) + O(n)
    
public:

    int solve(vector<int>& coins, int target,int n,vector<vector<int>> &dp) {

        // base case
        if(n == 0) {
            if(target % coins[n] == 0) {
                return 1;
            }
            else {
                return 0;
            }
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        int notpick = solve(coins,target,n-1,dp);

        int pick = 0;

        if(coins[n] <= target) {
            pick = solve(coins,target-coins[n],n,dp); // we can pick same coins for infinite times
        }

        return dp[n][target] = notpick + pick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans = solve(coins,amount,n-1,dp);
        
        if(ans == 0) {
            return 0;
        }
        return ans;
    }
};


class Solution {

    // 3.Tabulation
    // TC : O(n * target)
    // SC : O(n * target)

public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        // base case
        for(int c = 0; c <= amount; c++) {
             if(c % coins[0] == 0) {
                dp[0][c] = 1;
            }
            else {
                dp[0][c] = 0;
            }
        }


        for(int i = 1; i < n; i++) {
            for(int c = 0; c <= amount; c++) {
                int notpick = 0 + dp[i-1][c];

                int pick = 0;

                if(coins[i] <= c) {
                    pick = dp[i][c - coins[i]]; // we can pick same coins for infinite times
                }

                dp[i][c] = notpick + pick;
            }
        }

        int ans = dp[n-1][amount];
        
        if(ans == 0) {
            return 0;
        }
        return ans;
        
    }
};


class Solution {

    // 4.Space optimization
    // TC : O(n * target)
    // SC : O(target)

public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int>prev(amount+1,0),curr(amount+1,0);

        // base case
        for(int c = 0; c <= amount; c++) {
             if(c % coins[0] == 0) {
                prev[c] = 1;
            }
            else {
                prev[c] = 0; // to prevent overflow
            }
        }


        for(int i = 1; i < n; i++) {
            for(int c = 0; c <= amount; c++) {
                int notpick = 0 + prev[c];

                int pick = 0;

                if(coins[i] <= c) {
                    pick =curr[c - coins[i]]; // we can pick same coins for infinite times
                }

                curr[c] = notpick + pick;
            }

            prev = curr;
        }

        int ans = prev[amount];
        
        if(ans == 0) {
            return 0;
        }
        return ans;
        
    }
};

