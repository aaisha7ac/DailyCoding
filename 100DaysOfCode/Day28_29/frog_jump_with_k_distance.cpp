// Using memoization
// TC : O(n * k)
// SC : O(n) + O(n), for stack and dp vector

int solve(int n,int k,vector<int> &height,vector<int> &dp) {

    if(n == 0) {
        return 0;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    int minsteps = INT_MAX;

    for(int i = 1; i <= k; i++) {

        if(n-i >= 0) {
            int jumps = solve(n-i,k,height,dp) + abs(height[n] - height[n-i]);
            minsteps = min(minsteps,jumps);
        }
        
    }

    return dp[n] = minsteps;
}

int minimizeCost(int n, int k, vector<int> &height) {
    // Write your code here.   
    vector<int>dp(n+1,-1);
    return solve(n-1,k,height,dp);

}


// Using tabulation
// TC : O(n * k)
// SC : O(n) , for stack space

int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.

    vector<int>dp(n,0);

    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        int minsteps = INT_MAX;
        for(int j = 1; j <= k; j++) {

            if(i - j >= 0) {
                int jumps = dp[i-j] + abs(height[i] - height[i-j]);
                minsteps = min(minsteps,jumps);
            }
        }

        dp[i] = minsteps;
    }
    
    return dp[n-1];
}

