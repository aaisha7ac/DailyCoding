class Solution {


    // Subsequence -- continuous or discontinuous common character in the given two string

    // Using top down dp
    // TC : 0(m * n)
    // SC : 0(m * n)

    int t[1001][1001];

public:

    int LCS(string text1,string text2,int m,int n) {

        // base case or initialization
        // if size of text1 or text2 is 0, it is not possible to form any subsequence

        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                   t[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(text1[i-1] == text2[j-1]) {
                   t[i][j] =  1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[m][n];

    }


    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        return LCS(text1,text2,m,n);
        
    }
};