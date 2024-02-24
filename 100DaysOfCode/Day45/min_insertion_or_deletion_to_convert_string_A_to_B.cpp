class Solution {
public:

    // Using tabulation
    // TC : O(n * m)
    // SC : O(n * m)


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



    int minDistance(string word1, string word2) {

        int length_of_lcs = longestCommonSubsequence(word1,word2);

        int n = word1.length();
        int m = word2.length();

        int deletion = n - length_of_lcs;
        int insertion = m - length_of_lcs;

        return insertion + deletion;
        
    }
};