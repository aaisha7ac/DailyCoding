// 1.Recursion
// TC : O(2^n)
// SC : O(n)

int solve(vector<int> &price,int ind,int len) {

	// base case
	// at ind == 0 length will be 1, so we need n rod of length 1
	if(ind == 0) {
		return price[0] * len;
	}
	
	int take = 0 + solve(price,ind-1,len);
	int not_take = INT_MIN;

	// ind + 1, 1 based indexing
	if(ind+1 <= len) {
		not_take = price[ind] + solve(price,ind,len-(ind+1)); // we can use rod of same lenth for multiple times
	}

	return max(take,not_take);

}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return solve(price,n-1,n);
}


// 2.Memoization
// TC : O(n * n)
// SC : O(n * n) + O(n)

int solve(vector<int> &price,int ind,int len,vector<vector<int>> &dp) {

	// base case
	// at ind == 0 length will be 1, so we need n rod of length 1
	// cost = n * length(1) * price[0]
	if(ind == 0) {
		return price[0] * len;
	}
	
	if(dp[ind][len] != -1) {
		return dp[ind][len];
	}


	int take = 0 + solve(price,ind-1,len,dp);
	int not_take = INT_MIN;

	// ind + 1, 1 based indexing
	if(ind+1 <= len) {
		not_take = price[ind] + solve(price,ind,len-(ind+1),dp); // we can use rod of same lenth for multiple times
	}

	return dp[ind][len] = max(take,not_take);

}


int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int len = n;

	vector<vector<int>>dp(n,vector<int>(len+1,-1));
	return solve(price,n-1,len,dp);
}


// 3.Tabulation
// TC : O(n * n)
// SC : O(n * n)

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int len = n;

	vector<vector<int>>dp(n,vector<int>(len+1,0));

	// at ind == 0 length will be 1, so we need n rod of length 1
	// cost = n * length(1) * price[0]
	for(int l = 1; l <= len; l++) {
		dp[0][l] = price[0] * l;
	}


	for(int ind = 1; ind < n; ind++) {
		for(int l = 1; l <= len; l++) {
			int take = 0 + dp[ind-1][l];
			int not_take = INT_MIN;

			// ind + 1, 1 based indexing
			if(ind+1 <= l) {
				not_take = price[ind] + dp[ind][l-(ind+1)]; // we can use rod of same lenth for multiple times
			}

			dp[ind][l] = max(take,not_take);
		}
	}


	return dp[n-1][len];
}


// 4.Space optimization
// TC : O(n * n)
// SC : O(n)

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	int len = n;

	vector<int>prev(len+1,0),curr(len+1,0);

	// at ind == 0 length will be 1, so we need n rod of length 1
	// cost = n * length(1) * price[0]
	for(int l = 1; l <= len; l++) {
		prev[l] = price[0] * l;
	}


	for(int ind = 1; ind < n; ind++) {
		for(int l = 1; l <= len; l++) {
			int take = 0 + prev[l];
			int not_take = INT_MIN;

			// ind + 1, 1 based indexing
			if(ind+1 <= l) {
				not_take = price[ind] + curr[l-(ind+1)]; // we can use rod of same lenth for multiple times
			}

			curr[l] = max(take,not_take);
		}
		prev = curr;
	}

	return prev[len];
}
