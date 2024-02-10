// Using recursion
// TC : O(3^n * 3^n)
// SC : O(n) , for auxiliary stack space

#include <bits/stdc++.h> 
using namespace std;

int solve(int row,int col1,int col2,vector<vector<int>> &grid,int m,int n) {

    // out of bound
    if(col1 < 0 || col2 < 0 || col1 >= m || col2 >= m) {
        return -1e8;
    }

    if(row == n - 1) {
        if(col1 == col2) {
            return grid[row][col1];
        }
        else {
            return grid[row][col1] + grid[row][col2];
        }
    }

    int ans = -1e8;

    for(int dcol1 = -1; dcol1 <= 1; dcol1++) {
        for(int dcol2 = -1; dcol2 <= 1; dcol2++) {
                int value = 0;
                if(col1 == col2) {
                    value = grid[row][col1];
                }
                else {
                    value = grid[row][col1] + grid[row][col2];
                }
                value += solve(row+1,col1+dcol1,col2+dcol2,grid,m,n);
                ans = max(ans,value);

        }
    }

    return ans;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    return solve(0,0,c-1,grid,c,r);
}


// Using memoization
// TC : O(row * col * col)
// SC : O(row * col * col) + O(n) ,for 3D dp vector and auxiliary stack space

#include <bits/stdc++.h> 
using namespace std;

int solve(int row,int col1,int col2,vector<vector<int>> &grid,int m,int n,vector<vector<vector<int>>> &dp) {

    // out of bound
    if(col1 < 0 || col2 < 0 || col1 >= m || col2 >= m) {
        return -1e8;
    }

    if(row == n - 1) {
        if(col1 == col2) {
            return grid[row][col1];
        }
        else {
            return grid[row][col1] + grid[row][col2];
        }
    }

    if(dp[row][col1][col2] != -1) {
        return dp[row][col1][col2];
    }

    int ans = -1e8;

    for(int dcol1 = -1; dcol1 <= 1; dcol1++) {
        for(int dcol2 = -1; dcol2 <= 1; dcol2++) {
                int value = 0;
                if(col1 == col2) {
                    value = grid[row][col1];
                }
                else {
                    value = grid[row][col1] + grid[row][col2];
                }
                value += solve(row+1,col1+dcol1,col2+dcol2,grid,m,n,dp);
                ans = max(ans,value);

        }
    }

    return dp[row][col1][col2] = ans;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.

    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));

    return solve(0,0,c-1,grid,c,r,dp);
}




