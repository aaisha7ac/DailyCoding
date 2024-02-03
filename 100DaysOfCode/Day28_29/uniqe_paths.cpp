class Solution {

    // Using memoization
    // TC : O(m*n)
    // SC : O((m-1) + (n-1)) + O(m * n), for path length and dp vector

public:

    int solve(int row,int col,vector<vector<int>>& dp) {

        if(row == 0 && col == 0) {
            return 1;
        }

        // out of bound
        if(row < 0 || col < 0) {
            return 0;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int up = solve(row-1,col,dp);
        int left = solve(row,col-1,dp);

        return dp[row][col] = up + left;
    }
    

    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};


class Solution {

    // Using tabulation
    // TC : O(m * n)
    // SC : O(m * n)

public:

    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m,vector<int>(n,0));
       
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(row == 0 && col == 0) {
                    dp[row][col] = 1;
                }
                else {
                    int up = 0;
                    int left = 0;
                    if(row > 0) up = dp[row-1][col];
                    if(col > 0) left = dp[row][col-1];
                    dp[row][col] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
    }
};