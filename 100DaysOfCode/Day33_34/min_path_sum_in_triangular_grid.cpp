class Solution {

    // Using memoization

public:

    int solve(int row,int n,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp) {
        
        // base case 
        // when we reach the last row we will consider the value at different column
        if(row == n - 1) {
            return triangle[n-1][col];
        }

        if(dp[row][col] != -1) {
            return dp[row][col];
        }

        // next row, same column
        int below = triangle[row][col] + solve(row+1,n,col,triangle,dp);

        // next row, next column
        int diagonal = triangle[row][col] + solve(row+1,n,col+1,triangle,dp);

        return dp[row][col] = min(below,diagonal);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int row = triangle.size();
        int col = triangle[0].size();

        vector<vector<int>>dp(row,vector<int>(row,-1));

        return solve(0,row,0,triangle,dp);
    }
};

class Solution {

    // Using tabulation
    // TC : O(row * row)
    // SC : O(row * row)

public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int row = triangle.size();

        vector<vector<int>>dp(row,vector<int>(row,-1));

        // base case
        for(int i = 0; i < row; i++) {
            dp[row-1][i] = triangle[row-1][i];
        }

        // will start the i from row-2 because row-1 (last row) is already computed
        for(int i = row - 2; i >= 0; i--) {
            for(int j = i; j >= 0; j--) {
                // next row, same column
                int below = triangle[i][j] + dp[i+1][j];

                // next row, next column
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(below,diagonal);
            }
        }

        return dp[0][0];
    }
};

class Solution {

    // Space optimization
    // TC : O(row * row)
    // SC : O(row)

public:

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int row = triangle.size();

        vector<int>front_row(row,0);

        // base case
        for(int i = 0; i < row; i++) {
            front_row[i] = triangle[row-1][i];
        }

        // will start the i from row-2 because row-1 (last row) is already computed
        for(int i = row - 2; i >= 0; i--) {

            vector<int>curr_row(row,0);

            for(int j = i; j >= 0; j--) {
                // next row, same column
                int below = triangle[i][j] + front_row[j];

                // next row, next column
                int diagonal = triangle[i][j] + front_row[j+1];

                curr_row[j] = min(below,diagonal);
            }

            front_row = curr_row;
        }

        return front_row[0];
    }
};