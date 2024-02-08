class Solution {

    // Using memoization
    // TC : O(row * col);
    // SC : O(row* col) + O((row-1) + (col-1)) , for 2D dp vector and length of the path

public:

    long long  solve(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& dp) {

        if(row == 0 && col == 0) {
            return grid[0][0];
        }

        if(row < 0 || 0 > col) {
            return INT_MAX;
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        long long up = grid[row][col] + solve(row-1,col,grid,dp);
        long long left = grid[row][col] + solve(row,col-1,grid,dp);

        return dp[row][col] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,-1));

        return solve(row-1,col-1,grid,dp);
        
    }
};


class Solution {

    // Using tabulation
    // TC : O(row * col);
    // SC : O(row* col) , for 2D dp vector

public:

    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(col,0));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[0][0];
                }
                else{
                    long long up = 0;
                    long long left = 0;
                    if(i > 0) {
                        up = grid[i][j] + dp[i-1][j];
                    }
                    else {
                        up = INT_MAX;
                    }

                    if(j > 0) {
                        left = grid[i][j] + dp[i][j-1];
                    }
                    else {
                        left = INT_MAX;
                    }

                    dp[i][j] = min(up,left);
                }
            }
        }
        
        return dp[row-1][col-1];
        
    }
};

class Solution {

    // Using space optimization
    // TC : O(row * col);
    // SC : O(col)

public:

    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<int>prev_col(col,0);

        for(int i = 0; i < row; i++) {
            vector<int>curr_col(col,0);
            for(int j = 0; j < col; j++) {
                if(i == 0 && j == 0) {
                    curr_col[j] = grid[0][0];
                }
                else{
                    long long up = 0;
                    long long left = 0;
                    if(i > 0) {
                        up = grid[i][j] + prev_col[j];
                    }
                    else {
                        up = INT_MAX;
                    }

                    if(j > 0) {
                        left = grid[i][j] + curr_col[j-1];
                    }
                    else {
                        left = INT_MAX;
                    }
                    
                    curr_col[j] = min(up,left);
                }
            }

            prev_col = curr_col;
        }

        return prev_col[col-1];
        
    }
};

