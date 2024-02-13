// 1. Recursion
// TC : O(2^n)
// SC : O(n) , auxiliary stack space

#include <bits/stdc++.h> 

bool solve(int ind,int target,vector<int> &arr) {

    if(target == 0) {
        return true;
    }

    if(ind == 0) {
        return (arr[ind] == target);
    }

    bool not_take = solve(ind-1,target,arr);
    
    bool take = false;
    if(arr[ind] <= target) {
        take = solve(ind-1,target - arr[ind],arr);
    }

    return take | not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    return solve(n-1,k,arr);
}


// 2. Memoization
// TC : O(ind * target)
// SC : O(ind * target) + 0(n) , for 2D dp vector and auxiliary stack space

#include <bits/stdc++.h> 

bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {

    if(target == 0) {
        return true;
    }

    if(ind == 0) {
        return (arr[ind] == target);
    }

    if(dp[ind][target] != -1) {
        return dp[ind][target];
    }

    bool not_take = solve(ind-1,target,arr,dp);
    
    bool take = false;
    if(arr[ind] <= target) {
        take = solve(ind-1,target - arr[ind],arr,dp);
    }

    return dp[ind][target] = take | not_take;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<vector<int>>dp(n,vector<int>(k+1,-1));

    return solve(n-1,k,arr,dp);
}


// 3. Tabulation
// TC : O(ind * target)
// SC : O(ind * target) , for 2D dp vector

#include <bits/stdc++.h> 

// bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {

//     if(target == 0) {
//         return true;
//     }

//     if(ind == 0) {
//         return (arr[ind] == target);
//     }

//     if(dp[ind][target] != -1) {
//         return dp[ind][target];
//     }

//     bool not_take = solve(ind-1,target,arr,dp);
    
//     bool take = false;
//     if(arr[ind] <= target) {
//         take = solve(ind-1,target - arr[ind],arr,dp);
//     }

//     return dp[ind][target] = take | not_take;
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<vector<bool>>dp(n,vector<bool>(k+1,0));

    // base case
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = true;

    for(int index = 1; index < n; index++) {
        for(int target = 1; target <= k; target++) {
                bool not_take = dp[index-1][target];
    
                bool take = false;
                if(arr[index] <= target) {
                    take = dp[index-1][target - arr[index]];
                }

                dp[index][target] = take | not_take;
        }
    }

    return dp[n-1][k];
}


// 4. Space optimization
// TC : O(ind * target)
// SC : O(target)

#include <bits/stdc++.h> 

// bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp) {

//     if(target == 0) {
//         return true;
//     }

//     if(ind == 0) {
//         return (arr[ind] == target);
//     }

//     if(dp[ind][target] != -1) {
//         return dp[ind][target];
//     }

//     bool not_take = solve(ind-1,target,arr,dp);
    
//     bool take = false;
//     if(arr[ind] <= target) {
//         take = solve(ind-1,target - arr[ind],arr,dp);
//     }

//     return dp[ind][target] = take | not_take;
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<bool>prev_row(k+1,0);
    vector<bool>curr_row(k+1,0);

    // base case
    prev_row[0] = curr_row[0] = true;

    if(arr[0] <= k) {
        prev_row[arr[0]] = true;
    }


    for(int index = 1; index < n; index++) {
        for(int target = 1; target <= k; target++) {
                bool not_take = prev_row[target];
    
                bool take = false;
                if(arr[index] <= target) {
                    take = prev_row[target - arr[index]];
                }

                curr_row[target] = take | not_take;
        }

        prev_row = curr_row;
    }

    return prev_row[k];
}