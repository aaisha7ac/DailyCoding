class Solution {

    // 1. Recursion
    // TC : O(exponential) 
    // SC : O(n + m) , auxiliary stack space
public:

    int solve(int n,int m,string s1,string s2) {

        // base case
        if(n < 0) {
            return m + 1;
        }

        if(m < 0) {
            return n + 1;
        }

        
        // recurrence 
        if(s1[n] == s2[m]) {
            return solve(n-1,m-1,s1,s2);
        }

        return 1 + min(solve(n-1,m,s1,s2),min(solve(n,m-1,s1,s2),solve(n-1,m-1,s1,s2)));

    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        return solve(n-1,m-1,word1,word2);
        
    }
};

class Solution {

    // 2.Memoization
    // TC : O(n * m) 
    // SC : O(n + m) + O(n * m) , auxiliary stack space and for memoization
    
public:

    int solve(int n,int m,string s1,string s2,vector<vector<int>> &dp) {

        // base case
        if(n == 0) {
            return m;
        }

        if(m == 0) {
            return n;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        
        // recurrence 
        if(s1[n-1] == s2[m-1]) {
            return dp[n][m] = solve(n-1,m-1,s1,s2,dp);
        }

        return dp[n][m] = 1 + min(solve(n-1,m,s1,s2,dp),min(solve(n,m-1,s1,s2,dp),solve(n-1,m-1,s1,s2,dp)));

    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n,m,word1,word2,dp);
        
    }
};

class Solution {

    // 3.Tabulation
    // TC : O(n * m) 
    // SC : O(n * m) , 2d dp vector

public:

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // base case
        for(int i = 0; i <= m; i++) {
            dp[0][i] = i;
        }

        for(int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }

            }
        }

        return dp[n][m];
        
    }
};

class Solution {

    // 4.Space optimizaton
    // TC : O(n * m) 
    // SC : O(m)

public:

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int>prev(m+1,0),curr(m+1,0);

        // base case
        for(int i = 0; i <= m; i++) {
            prev[i] = i;
        }

        for(int i = 1; i <= n; i++) {
            curr[0] = i;
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) {
                    curr[j] = prev[j-1];
                }
                else {
                    curr[j] = 1 + min(prev[j],min(curr[j-1],prev[j-1]));
                }

            }
            prev = curr;
        }

        return prev[m];
        
    }
};