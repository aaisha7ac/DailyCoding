class Solution {

    // Using tabulation
    // TC : O(n * m)
    // SC : O(n * m)

public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();

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
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // if string at curr index does not matches we will reduce lenght of first string and check and reduce the lenght of second string and check
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j - 1]);
                }

            }
        }


        int length_of_LCS = dp[n][m];
        int len = n + m - length_of_LCS;

        string ans = "";
        
        for(int i = 0; i < len; i++) {
            ans += '$';
        }

        int i = n, j = m;
        len--;

        // here we are taking common character once, as well as not common character in ans
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                ans[len] = str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans[len] = str1[i-1];
                i--;
            }
            else { // dp[i-1][j] < dp[i][j-1]) 
                ans[len] = str2[j-1];
                j--;
            }
            len--;
        }


        while(i > 0) {
            ans[len] = str1[i-1];
            i--;
            len--;
        }

        while(j > 0) {
            ans[len] = str2[j-1];
            j--;
            len--;
        }

        return ans;
    }
};