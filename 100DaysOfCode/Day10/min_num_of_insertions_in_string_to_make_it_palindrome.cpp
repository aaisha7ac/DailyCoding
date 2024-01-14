class Solution {
public:
    // Using tabulation
    // TC : O(n * n)
    // SC : O(n * n)

    int t[501][501];

    int longest_common_subsequence(string X,string Y,int m,int n) {

        // base case or initialization
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }

        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(X[i-1] == Y[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[m][n];
    }


    int minInsertions(string s) {

        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());

        int length_of_LCS = longest_common_subsequence(s,t,n,n);

        // no of deletion = no of insertion
        // no of insertions = n - length_of_LCS

        return n - length_of_LCS;
    }
};