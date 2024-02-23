class Solution {

    // 1.Recurion
    // TC : O(2^n * 2^m)
    // SC : O(n * m)
    
public:

    int solve(string text1, string text2,int n,int m) {

        // base case
        if(n < 0 || m < 0) {
            return 0;
        }

        // if string st curr index matches we will reduce lenght of both string
        if(text1[n] == text2[m]) {
            return 1 + solve(text1,text2,n-1,m-1);
        }

        // if string st curr index does not matches we will reduce lenght of first string and check and reduce the lenght of second string check
        return max(solve(text1,text2,n-1,m),solve(text1,text2,n,m-1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        return solve(text1,text2,n-1,m-1);
    }
};


class Solution {

    // 2.Memoization
    // TC : O(n * m)
    // SC : O(n * m) + O(n * m)
public:

    int solve(string text1, string text2,int n,int m,vector<vector<int>> &dp) {

        // base case
        if(n < 0 || m < 0) {
            return 0;
        }

        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        // if string at curr index matches we will reduce lenght of both string
        if(text1[n] == text2[m]) {
            return dp[n][m] = 1 + solve(text1,text2,n-1,m-1,dp);
        }

        // if string at curr index does not matches we will reduce lenght of first string and check and reduce the lenght of second string and check
        return dp[n][m] = max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>>dp(1001,vector<int>(1001,-1));

        return solve(text1,text2,n-1,m-1,dp);
    }
};

class Solution {

    // 3.Tabulation
    // TC : O(n * m)
    // SC : O(n * m)


public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(1001,vector<int>(1001,0));

        // base case
        for(int i = 0; i < m; i++) {
            dp[i][0] = 0;
        }

        for(int i = 0; i < n; i++) {
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // if string at curr index matches we will reduce lenght of both string
                if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // if string at curr index does not matches we will reduce lenght of first string and check and reduce the lenght of second string and check
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j - 1]);
                }

            }
        }
        
        return dp[n][m];
    }
};

class Solution {

    // 4.Space optimization
    // TC : O(n * m)
    // SC : O(n)


public:

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<int>prev(1001,0), curr(1001,0);

        // base case
        // we only need previous row, no need of previous column
        for(int i = 0; i < 1001; i++) {
            prev[i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                // if string at curr index matches we will reduce lenght of both string
                if(text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + prev[j-1];
                }

                // if string at curr index does not matches we will reduce lenght of first string and check and reduce the lenght of second string and check
                else {
                    curr[j] = max(prev[j],curr[j - 1]);
                }

            }

            prev = curr;
        }
        
        return prev[m];
    }
};