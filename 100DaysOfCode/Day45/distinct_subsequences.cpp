class Solution {
    // 1.Recursion
    // TC : O(2 ^(n+m))
    // SC : O(n + m) auxiliary stack space

    // 2.Memoization
    // TC : O(n * m)
    // SC : O(n + m) + O(n + m), for memoization and auxiliary stack space

public:

    int solve(int n,int m,vector<vector<int>> &dp,string s,string t) {

        // base case 
        if(m == 0) {
            return 1;
        }

        if(n == 0) {
            return 0;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        if(s[n-1] == t[m-1]) {
            return dp[n][m] = solve(n-1,m-1,dp,s,t) + solve(n-1,m,dp,s,t);
        }

        else {
            return dp[n][m] = solve(n-1,m,dp,s,t);
        }
    }


    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n,m,dp,s,t);
        
    }
};


class Solution {
    
    // 3.Tabulation
    // TC : O(n * m)
    // SC : O(n + m)

public:

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<vector<double>>dp(n+1,vector<double>(m+1,0));

        // base case
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }
                else {
                     dp[i][j] =  dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};


class Solution {
    
    // 4.Space optimization
    // TC : O(n * m)
    // SC : O(m)

public:

    int numDistinct(string s, string t) {

        int n = s.length();
        int m = t.length();

        vector<double>prev(m+1,0),curr(m+1,0);

        // base case
        prev[0] = curr[0] = 1;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s[i-1] == t[j-1]) {
                    curr[j] = prev[j-1] + prev[j];
                }
                else {
                    curr[j] =  prev[j];
                }
            }

            prev = curr;
        }
        
        return prev[m];
    }
};
