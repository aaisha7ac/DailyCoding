class Solution {

    // 1. Using Recursion
    // TC : O(2^n)
    // SC : O(n) , auxiliary stack space

public:

    int solve(int ind,string s) {

        if(ind == s.length()) return 1;

        if(s[ind] == '0') return 0;

        int one = solve(ind + 1,s);
        int two = 0;

        if(ind + 1 < s.length() && (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')) {
            two = solve(ind + 2,s);
        }

        return one + two;
    }

    int numDecodings(string s) {

        return solve(0,s);
        
    }
};




class Solution {

    // 2. Using Memoization
    // TC : O(n)
    // SC : O(n) + O(n) auxiliary stack space and for memoization

public:

    int solve(int ind,string s,vector<int> &dp) {

        if(ind == s.length()) return 1;

        if(s[ind] == '0') return 0;

        if(dp[ind] != -1) {
            return dp[ind];
        }

        int one = solve(ind + 1,s,dp);
        int two = 0;

        if(ind + 1 < s.length() && (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')) {
            two = solve(ind + 2,s,dp);
        }

        return dp[ind] = one + two;
    }

    int numDecodings(string s) {

        vector<int>dp(101,-1);

        return solve(0,s,dp);
        
    }
};




class Solution {

    // 3. Using Tabulation
    // TC : O(n)
    // SC : O(n)

public:

    // int solve(int ind,string s,vector<int> &dp) {

    //     if(ind == s.length()) return 1;

    //     if(s[ind] == '0') return 0;

    //     if(dp[ind] != -1) {
    //         return dp[ind];
    //     }

    //     int one = solve(ind + 1,s,dp);
    //     int two = 0;

    //     if(ind + 1 < s.length() && (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')) {
    //         two = solve(ind + 2,s,dp);
    //     }

    //     return dp[ind] = one + two;
    // }

    int numDecodings(string s) {

        vector<int>dp(101,0);
        
        int n = s.length();
        
        dp[n] = 1;

        for(int ind = n - 1; ind >= 0; ind--) {

            if(s[ind] == '0') {
                dp[ind] = 0;
            }
            else {
                int one = dp[ind + 1];
                int two = 0;
                if(ind + 1 < n && (s[ind] == '1' || s[ind] == '2' && s[ind + 1] <= '6')) {
                    two = dp[ind + 2];
                }
                dp[ind] = one + two;
            }
        }

        return dp[0];
        
    }
};