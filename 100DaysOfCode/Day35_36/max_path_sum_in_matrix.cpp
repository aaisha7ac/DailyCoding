// TC : O(3^n)
// SC : O(n) , auxiliary stack space

#include <bits/stdc++.h> 
using namespace std;

int solve(int row,int col,int m,vector<vector<int>> &matrix) {

    if(col < 0 || col >= m) {
        return -1e8;
    }

    if(row == 0) {
        return matrix[0][col];
    }

    int up = matrix[row][col] + solve(row-1,col,m,matrix);
    int up_left_diagonal = matrix[row][col] + solve(row-1,col-1,m,matrix);
    int up_right_diagonal = matrix[row][col] + solve(row-1,col+1,m,matrix);


    return max({up,up_left_diagonal,up_right_diagonal});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int row = matrix.size();
    int col = matrix[0].size();

    int n = row;
    int m = col;

    int ans = INT_MIN;
    for(int i = 0; i < col; i++) {
        int temp = solve(row-1,i,m,matrix);
        ans = max(ans,temp);
    }

    return ans;
}


// 2.Memoization
// TC : O(row * col)
// SC : O(row* col) + O(n) ,for 2D dp vector and auxiliary stack space

#include <bits/stdc++.h> 
using namespace std;

int solve(int row,int col,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp) {

    // out of bound case
    if(col < 0 || col >= m) {
        return -1e8;
    }

    if(row == 0) {
        return matrix[0][col];
    }

    if(dp[row][col] != -1) {
        return dp[row][col];
    }

    int up = matrix[row][col] + solve(row-1,col,m,matrix,dp);
    int up_left_diagonal = matrix[row][col] + solve(row-1,col-1,m,matrix,dp);
    int up_right_diagonal = matrix[row][col] + solve(row-1,col+1,m,matrix,dp);


    return dp[row][col] = max({up,up_left_diagonal,up_right_diagonal});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int row = matrix.size();
    int col = matrix[0].size();

    int n = row;
    int m = col;

    vector<vector<int>>dp(row,vector<int>(col,-1));

    int ans = INT_MIN;
    for(int i = 0; i < col; i++) {
        int temp = solve(row-1,i,m,matrix,dp);
        ans = max(ans,temp);
    }

    return ans;
}





// 3.Tabulation
// TC : O(row * col)
// SC : O(row* col),for 2D dp vector

#include <bits/stdc++.h> 
using namespace std;

// int solve(int row,int col,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp) {

//     // out of bound case
//     if(col < 0 || col >= m) {
//         return -1e8;
//     }

//     if(row == 0) {
//         return matrix[0][col];
//     }

//     if(dp[row][col] != -1) {
//         return dp[row][col];
//     }

//     int up = matrix[row][col] + solve(row-1,col,m,matrix,dp);
//     int up_left_diagonal = matrix[row][col] + solve(row-1,col-1,m,matrix,dp);
//     int up_right_diagonal = matrix[row][col] + solve(row-1,col+1,m,matrix,dp);


//     return dp[row][col] = max({up,up_left_diagonal,up_right_diagonal});
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>>dp(row,vector<int>(col,0));

    // base case

    for(int j = 0; j < col; j++) {
        dp[0][j] = matrix[0][j];
    }


    for(int i = 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int up = matrix[i][j] + dp[i-1][j];
            int up_left_diagonal = INT_MIN;
            int up_right_diagonal = INT_MIN;
            if(j - 1 >= 0) up_left_diagonal = matrix[i][j] + dp[i-1][j-1];
            if(j + 1 < col) up_right_diagonal = matrix[i][j] + dp[i-1][j+1];
            dp[i][j] = max({up,up_left_diagonal,up_right_diagonal});
        }
    }


    int ans = INT_MIN;
    for(int j = 0; j < col; j++) {
        ans = max(ans,dp[row-1][j]);
    }

    return ans;
 
}



// 3. Space optimization
// TC : O(row * col)
// SC : O(col)

#include <bits/stdc++.h> 
using namespace std;

// int solve(int row,int col,int m,vector<vector<int>> &matrix,vector<vector<int>> &dp) {

//     // out of bound case
//     if(col < 0 || col >= m) {
//         return -1e8;
//     }

//     if(row == 0) {
//         return matrix[0][col];
//     }

//     if(dp[row][col] != -1) {
//         return dp[row][col];
//     }

//     int up = matrix[row][col] + solve(row-1,col,m,matrix,dp);
//     int up_left_diagonal = matrix[row][col] + solve(row-1,col-1,m,matrix,dp);
//     int up_right_diagonal = matrix[row][col] + solve(row-1,col+1,m,matrix,dp);


//     return dp[row][col] = max({up,up_left_diagonal,up_right_diagonal});
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.

    int row = matrix.size();
    int col = matrix[0].size();

    vector<int>prev_col(col,0);

    // base case
    for(int j = 0; j < col; j++) {
        prev_col[j] = matrix[0][j];
    }

    vector<int>curr_col(col,0);


    for(int i = 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int up = matrix[i][j] + prev_col[j];
            int up_left_diagonal = INT_MIN;
            int up_right_diagonal = INT_MIN;
            if(j - 1 >= 0) up_left_diagonal = matrix[i][j] + prev_col[j-1];
            if(j + 1 < col) up_right_diagonal = matrix[i][j] + prev_col[j+1];
            curr_col[j] = max({up,up_left_diagonal,up_right_diagonal});
        }
        prev_col = curr_col;
    }


    int ans = INT_MIN;
    for(int j = 0; j < col; j++) {
        ans = max(ans,prev_col[j]);
    }

    return ans;
 
}