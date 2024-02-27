class Solution {

    // 1.Recursion
    // TC : O(exponential)
    // SC : O(n + m)
    
public:

    bool solve(int i,int j,string &p,string &s) {

        // base case
        if(i < 0 && j < 0) {
            return true;
        }

        if(i < 0 && j >= 0) {
            return false;
        }

        if(i >= 0 && j < 0) {
            for(int k = 0; k <= i; k++) {
                if(p[k] != '*') {
                    return false;
                }
            }

            return true;
        }
        
        // recurrsion
        if(p[i] == s[j] || p[i] == '?') {
            return solve(i-1,j-1,p,s);
        }
        if(p[i] == '*') {
            return solve(i-1,j,p,s) | solve(i,j-1,p,s);
        }

        return false;
       
    }


    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        return solve(m-1,n-1,p,s);
    }
};

class Solution {

    // 2.Memoization
    // TC : O(n * m)
    // SC : O(n + m) + O(n * m)

public:

    bool solve(int i,int j,string &p,string &s,vector<vector<int>> &dp) {

        // base case
        if(i == 0 && j == 0) {
            return true;
        }

        if(i == 0 && j > 0) {
            return false;
        }

        if(i > 0 && j == 0) {
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') {
                    return false;
                }
            }

            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // recurrsion
        if(p[i-1] == s[j-1] || p[i-1] == '?') {
            return dp[i][j] = solve(i-1,j-1,p,s,dp);
        }

        if(p[i-1] == '*') {
            return dp[i][j] = solve(i-1,j,p,s,dp) | solve(i,j-1,p,s,dp);
        }

        return false;
       
    }


    bool isMatch(string s, string p) {

        int n = p.length();
        int m = s.length();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(n,m,p,s,dp);
    }
};

class Solution {

    // 3.Tabulation
    // TC : O(n * m)
    // SC : O(n * m)

public:

    // bool solve(int i,int j,string &p,string &s,vector<vector<int>> &dp) {

    //     // base case
    //     if(i == 0 && j == 0) {
    //         return true;
    //     }

    //     if(i == 0 && j > 0) {
    //         return false;
    //     }

    //     if(i > 0 && j == 0) {
    //         for(int k = 0; k < i; k++) {
    //             if(p[k] != '*') {
    //                 return false;
    //             }
    //         }

    //         return true;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
        
    //     // recurrsion
    //     if(p[i-1] == s[j-1] || p[i-1] == '?') {
    //         return dp[i][j] = solve(i-1,j-1,p,s,dp);
    //     }

    //     if(p[i-1] == '*') {
    //         return dp[i][j] = solve(i-1,j,p,s,dp) | solve(i,j-1,p,s,dp);
    //     }

    //     return false;
       
    // }


    bool isMatch(string s, string p) {

        int n = p.length();
        int m = s.length();

        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

        // base case
        
        dp[0][0] = true;

        for(int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int k = 1; k <= i; k++) {
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
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

    // bool solve(int i,int j,string &p,string &s,vector<vector<int>> &dp) {

    //     // base case
    //     if(i == 0 && j == 0) {
    //         return true;
    //     }

    //     if(i == 0 && j > 0) {
    //         return false;
    //     }

    //     if(i > 0 && j == 0) {
    //         for(int k = 0; k < i; k++) {
    //             if(p[k] != '*') {
    //                 return false;
    //             }
    //         }

    //         return true;
    //     }

    //     if(dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
        
    //     // recurrsion
    //     if(p[i-1] == s[j-1] || p[i-1] == '?') {
    //         return dp[i][j] = solve(i-1,j-1,p,s,dp);
    //     }

    //     if(p[i-1] == '*') {
    //         return dp[i][j] = solve(i-1,j,p,s,dp) | solve(i,j-1,p,s,dp);
    //     }

    //     return false;
       
    // }


    bool isMatch(string s, string p) {

        int n = p.length();
        int m = s.length();

        vector<bool>prev(m+1,false),curr(m+1,false);

        // base case
        
        prev[0] = true;

        for(int j = 1; j <= m; j++) {
            prev[j] = false;
        }


        // recurrence

        for(int i = 1; i <= n; i++) {

            bool flag = true;
            for(int k = 1; k <= i; k++) {
                if(p[k-1] != '*') {
                    flag = false;
                    break;
                }
            }

            curr[0] = flag;

            for(int j = 1; j <= m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if(p[i-1] == '*') {
                    curr[j] = prev[j] | curr[j-1];
                }
                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }
};