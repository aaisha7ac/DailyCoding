// 2.Memoization
// TC : O(n * W)
// SC : O(n * W) + O(n)

#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> profit, int n, int W,vector<vector<int>> &dp) {

	//base case
	if(n == 0) {
		return (W/weight[0]) * profit[0];
	}

	if(dp[n][W] != -1) {
		return dp[n][W];
	}


	int notPick = 0 + solve(weight,profit,n-1,W,dp);

	int pick = INT_MIN;
	if(weight[n] <= W) {
		pick = profit[n] + solve(weight,profit,n,W-weight[n],dp);
	}

	return dp[n][W] = max(notPick,pick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.

    vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return solve(weight,profit,n-1,w,dp);
}


// 3.Tabulation
// TC : O(n * W)
// SC : O(n * W)

#include <bits/stdc++.h>

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.

    vector<vector<int>>dp(n,vector<int>(w+1,0));

	// base case
	for(int W = weight[0]; W <= w; W++) {
		dp[0][W] = (W/weight[0]) * profit[0];
	}

	for(int i = 1; i < n; i++) {
		for(int W = 0; W <= w; W++) {
			int notPick = 0 + dp[i-1][W];

			int pick = INT_MIN;
			if(weight[i] <= W) {
				pick = profit[i] + dp[i][W-weight[i]]; // can use same item for infinite times
			}

			dp[i][W] = max(notPick,pick);
		}
	}

	return dp[n-1][w];
}



// 4.Space optimization
// TC : O(n * W)
// SC : O(W)

#include <bits/stdc++.h> 

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.

    // Write your code here
	vector<int>prev(w+1,0),curr(w+1,0);

	// base case
	for(int W = weight[0]; W <= w; W++) {
		prev[W] = (W/weight[0]) * profit[0];
	}

	for(int i = 1; i < n; i++) {
		for(int W = 0; W <= w; W++) {
			int notPick = 0 + prev[W];

			int pick = INT_MIN;
			if(weight[i] <= W) {
				pick = profit[i] + curr[W-weight[i]]; // we can pick same item for multiple times
			}

			curr[W] = max(notPick,pick);
		}

		prev = curr;
	}

	return prev[w];
}