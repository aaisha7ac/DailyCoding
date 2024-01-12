class Solution {

    // TC : O(m * n)
    // SC : O(m * n)

public:
    int t[1001][1001];

    int longest_common_subsequence(string str1, string str2,int m,int n) {

        // base condition or initialization
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }


        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(str1[i-1] == str2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        return t[m][n];
    }


    string shortestCommonSupersequence(string str1, string str2) {
        
        int m = str1.length();
        int n = str2.length();

        int length_of_LCS = longest_common_subsequence(str1,str2,m,n);

        int length = m + n - length_of_LCS;
        string ans = "";
        int index = length - 1;

        for(int i = 0; i < length; i++) {
            ans += '$';
        }

        int i = m;
        int j = n;


        // While printing shortest common supersequence both equal and different characters need to be considered

        while(i > 0 && j > 0) {

            if(str1[i-1] == str2[j-1]) {
                ans[index] = str1[i-1];
                i--;
                j--;
                index--;
            }

            else if(t[i][j-1] > t[i-1][j]) {
                ans[index] = str2[j-1];
                j--;
                index--;
            }

            else { //t[i][j-1] < t[i-1][j]
                ans[index] = str1[i-1];
                i--;
                index--;
            }
        }


        while(i > 0) {
            ans[index] = str1[i-1];
            i--;
            index--;
        }

        while(j > 0) {
            ans[index] = str2[j-1];
            j--;
            index--;
        }

        return ans;

    }
};