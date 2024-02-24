// Same code as Longest Common Subsequence, only few changes to be done
// Tabulation 
// TC : O(n*m)
// SC : O(n*m)

int lcs(string &str1, string &str2){
    // Write your code here.

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>>dp(1001,vector<int>(1001,0));

	//base condition
	for(int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}	

	for(int i = 0; i < m; i++) {
		dp[0][i] = 0;
	}	

    int ans = INT_MIN;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(str1[i-1] == str2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
			}
			else {
				dp[i][j] = 0; // only change in code of Longest Common Subsequence
			}
		}
	}

    return ans;

}