// Tabulation 
// TC : O(n*m)
// SC : O(n*m)


string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.

	vector<vector<int>>dp(1001,vector<int>(1001,0));

	//base condition
	for(int i = 0; i < n; i++) {
		dp[i][0] = 0;
	}	

	for(int i = 0; i < m; i++) {
		dp[0][i] = 0;
	}	


	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}


	int len = dp[n][m];

	string ans = "";

	for(int i = 0; i < len; i++) {
		ans += '$';
	}

	len--;
	int i = n, j = m;

	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			ans[len] = s1[i-1];
			len--;
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else { // dp[i-1][j] < d[i][j-1]
			j--;
		}
	}

	return ans;


	
}