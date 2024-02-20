// 2.Memoization
// TC : O(n * W)
// SC : O(n * W) + O(n)

#include <bits/stdc++.h> 

int solve(vector<int> weight, vector<int> value, int n, int W,vector<vector<int>> &dp) {

	//base case
	if(n == 0) {
		if(weight[0] <= W) {
			return value[0];
		}
		else {
			return 0;
		}
	}

	if(dp[n][W] != -1) {
		return dp[n][W];
	}


	int notPick = 0 + solve(weight,value,n-1,W,dp);

	int pick = INT_MIN;
	if(weight[n] <= W) {
		pick = value[n] + solve(weight,value,n-1,W-weight[n],dp);
	}

	return dp[n][W] = max(notPick,pick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);

}


// 3.Tabulation
// TC : O(n * W)
// SC : O(n * W)

#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

	// base case
	for(int w = weight[0]; w <= maxWeight; w++) {
		dp[0][w] = value[0];
	}

	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= maxWeight; w++) {
			int notPick = 0 + dp[i-1][w];

			int pick = INT_MIN;
			if(weight[i] <= w) {
				pick = value[i] + dp[i-1][w-weight[i]];
			}

			dp[i][w] = max(notPick,pick);
		}
	}

	return dp[n-1][maxWeight];


}


// 4.Space optimization
// TC : O(n * W)
// SC : O(W)

#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);

	// base case
	for(int w = weight[0]; w <= maxWeight; w++) {
		prev[w] = value[0];
	}

	for(int i = 1; i < n; i++) {
		for(int w = 0; w <= maxWeight; w++) {
			int notPick = 0 + prev[w];

			int pick = INT_MIN;
			if(weight[i] <= w) {
				pick = value[i] + prev[w-weight[i]];
			}

			curr[w] = max(notPick,pick);
		}

		prev = curr;
	}

	return prev[maxWeight];


}