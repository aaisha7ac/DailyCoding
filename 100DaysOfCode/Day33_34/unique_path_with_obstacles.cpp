class Solution {

    // Using memoization
    // TC : O(row*col)
    // SC : O((row-1) + (col-1)) + O(row * col), for path length and dp vector

public:

    // int mod = 2000000000;

    int solve(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        
        // this line of code is only added 
        if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1) {
            return 0;
        }

        if(row == 0 && col == 0) {
            return 1;
        }

        if(row < 0 || col < 0) {
            return 0;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        int up = solve(row-1,col,obstacleGrid,dp);
        int left = solve(row,col-1,obstacleGrid,dp);

        return dp[row][col] = (up + left); //% mod;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-1));

        return solve(row-1,col-1,obstacleGrid,dp);
    }
};


class Solution {

    // Using tabulation
    // TC : O(row*col)
    // SC : O(row*col), for dp vector

public:

    // int mod = 2000000000;

    // int solve(int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        
    //     // this line of code is only added 
    //     if(row >= 0 && col >= 0 && obstacleGrid[row][col] == 1) {
    //         return 0;
    //     }

    //     if(row == 0 && col == 0) {
    //         return 1;
    //     }

    //     if(row < 0 || col < 0) {
    //         return 0;
    //     }

    //     if(dp[row][col] != -1) {
    //         return dp[row][col];
    //     }

    //     int up = solve(row-1,col,obstacleGrid,dp);
    //     int left = solve(row,col-1,obstacleGrid,dp);

    //     return dp[row][col] = (up + left); //% mod;

    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,0));

        // return solve(row-1,col-1,obstacleGrid,dp);

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else if(i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    // int up = dp[i-1][j];
                    // int right = dp[i][j-1];
                    // dp[i][j] = up + right;

                    int up = 0;
                    int right = 0;

                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) right = dp[i][j-1];
                    dp[i][j] = up + right;
                }
            }
        }

        return dp[row-1][col-1];
    }
};


class Solution {

    // Using space optimization
    // TC : O(row*col)
    // SC : O(col)

public:

    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<int>prev_col(col,0);

        for(int i = 0; i < row; i++) {

            vector<int>curr_col(col,0);

            for(int j = 0; j < col; j++) {

                if(obstacleGrid[i][j] == 1) {
                    curr_col[j] = 0;
                }
                else if(i == 0 && j == 0) {
                    curr_col[j] = 1;
                }
                else {

                    int up = 0;
                    int right = 0;

                    if(i > 0) up = prev_col[j];
                    if(j > 0) right = curr_col[j-1];
                    curr_col[j] = up + right;
                }
                
            }

            prev_col = curr_col;

        }

        return prev_col[col-1];
    }
};
