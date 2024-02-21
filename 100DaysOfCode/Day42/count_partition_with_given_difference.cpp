// 2.Memoization
// TC : O(n * target)
// SC : O(n * target) + O(n)


#include <bits/stdc++.h> 
int mod = 1e9+7;

int solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {

    
	if(ind == 0) {

		// we have to choicess pick and not pick
		if(target == 0 && arr[0] == 0) {
			return 2;
		}

		// we only have 1 choice
		if(target == 0 || target == arr[0]) return 1;

		return 0;
	}


    if(dp[ind][target] != -1) {
        return dp[ind][target];
    }

    int not_take = solve(ind-1,target,arr,dp);
    
    int take = 0;
    if(arr[ind] <= target) {
        take = solve(ind-1,target - arr[ind],arr,dp);
    }

    return dp[ind][target] = (take + not_take) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int target = (sum - d) / 2;

                    // target cannot be fractional
    if(target < 0 || (sum - d) % 2 != 0) {
        return 0;
    }

    vector<vector<int>>dp(n,vector<int>(target+1,-1));


    return solve(n-1,target,arr,dp);


}


// 3.Tabulation
// TC : O(n * target)
// SC : O(n * target)


#include <bits/stdc++.h> 
int mod = 1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int target = (sum - d) / 2;

                    // target cannot be fractional
    if(target < 0 || (sum - d) % 2 != 0) {
        return 0;
    }

    vector<vector<int>>dp(n,vector<int>(target+1,0));


    // base case
    for(int t = 0; t <= target; t++) {
        // we have to choicess pick and not pick
		if(t == 0 && arr[0] == 0) {
			dp[0][t] = 2;
		}

		// we only have 1 choice
		else if(t == 0 || t == arr[0]) {
            dp[0][t] = 1;
        }
        else {
            dp[0][t] = 0;
        }
    }

    for(int ind = 1; ind < n; ind++) {
        for(int t = 0; t <= target; t++) {
            int not_take = dp[ind-1][t];
    
            int take = 0;
            if(arr[ind] <= t) {
                take = dp[ind-1][t-arr[ind]];
            }

            dp[ind][t] = (take + not_take) % mod;
        }
    }

    return dp[n-1][target];


}



// 4.Space optimaizatio
// TC : O(n * target)
// SC : O(target)


#include <bits/stdc++.h> 
int mod = 1e9+7;

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int target = (sum - d) / 2;

                    // target cannot be fractional
    if(target < 0 || (sum - d) % 2 != 0) {
        return 0;
    }

    vector<int>prev(target+1,0),curr(target+1,0);


    // base case
    for(int t = 0; t <= target; t++) {
        // we have to choicess pick and not pick
		if(t == 0 && arr[0] == 0) {
			prev[t] = 2;
		}

		// we only have 1 choice
		else if(t == 0 || t == arr[0]) {
            prev[t] = 1;
        }
        else {
            prev[t] = 0;
        }
    }

    for(int ind = 1; ind < n; ind++) {
        for(int t = 0; t <= target; t++) {
            int not_take = prev[t];
    
            int take = 0;
            if(arr[ind] <= t) {
                take = prev[t-arr[ind]];
            }

            curr[t] = (take + not_take) % mod;
        }

        prev = curr;
    }

    return prev[target];


}







