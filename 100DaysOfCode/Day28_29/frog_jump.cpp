// Using memoization
// TC : O(n)
// SC : O(n) + O(n) , for stack space and for dp vector

#include <bits/stdc++.h> 

int solve(int n,vector<int> &heights,vector<int> &dp) {

    if(n == 0) {
        return n;
    }

    if(dp[n] != -1) {
        return dp[n];
    }
    
    int left = solve(n-1,heights,dp) + abs(heights[n] - heights[n-1]);

    int right = INT_MAX;
    if(n > 1) {
        right = solve(n-2,heights,dp) + abs(heights[n] - heights[n-2]);
    }

    return dp[n] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int>dp(n+1,-1);

    solve(n-1,heights,dp);

    return dp[n-1];
}


// Using tabulation
// TC : O(n)
// SC : O(n) , for dp vector

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int>dp(n);

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);

        int right = INT_MAX;

        if(i > 1) {
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }

        dp[i] = min(left,right);
    }

    return dp[n-1];

}

// Using space optmisation
// TC : O(n)
// SC : O(1)

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    int prev = 0;
    int prev2 = 0;

    for(int i = 1; i < n; i++) {
        int left = prev + abs(heights[i] - heights[i-1]);

        int right = INT_MAX;

        if(i > 1) {
            right = prev2 + abs(heights[i] - heights[i-2]);
        }

        int curr = min(left,right);

        prev2 = prev;
        prev = curr;
    }

    return prev;
}