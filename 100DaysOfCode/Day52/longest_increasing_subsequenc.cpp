class Solution {
    
    // 1.Recursion
    // TC : O(2^n)
    // SC : O(n) , auxiliary stack space

public:
    int solve(int ind,int prev,int n,vector<int>& nums) {

        if(ind == n) {
            return 0;
        }

        int not_take = 0 + solve(ind + 1, prev, n, nums);
 
        int take = INT_MIN;

        if(prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, n, nums);
        }

        return max(not_take,take);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        return solve(0,-1,n,nums);
    }
};


class Solution {
    
    // 2.Memoization
    // TC : O(n * n)
    // SC : O(n * n) + O(n)

public:
    int solve(int ind,int prev_ind,int n,vector<int>& nums,vector<vector<int>> &dp) {

        if(ind == n) {
            return 0;
        }

        if(dp[ind][prev_ind + 1] != -1) {
            return dp[ind][prev_ind + 1];
        }
        int not_take = 0 + solve(ind + 1, prev_ind, n, nums,dp);
 
        int take = INT_MIN;

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
            take = 1 + solve(ind + 1, ind, n, nums,dp);
        }

        return dp[ind][prev_ind + 1] = max(take,not_take);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,n,nums,dp);
    }
};

class Solution {
    
    // 3.Tabulation
    // TC : O(n * n)
    // SC : O(n * n)

public:
    // int solve(int ind,int prev_ind,int n,vector<int>& nums,vector<vector<int>> &dp) {

    //     if(ind == n) {
    //         return 0;
    //     }

    //     if(dp[ind][prev_ind + 1] != -1) {
    //         return dp[ind][prev_ind + 1];
    //     }
    //     int not_take = 0 + solve(ind + 1, prev_ind, n, nums,dp);
 
    //     int take = INT_MIN;

    //     if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
    //         take = 1 + solve(ind + 1, ind, n, nums,dp);
    //     }

    //     return dp[ind][prev_ind + 1] = max(take,not_take);
    // }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int prev_ind = n - 1; prev_ind >= -1; prev_ind--) {
                int not_take = 0 + dp[ind + 1][prev_ind + 1];
 
                int take = INT_MIN;

                if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    take = 1 + dp[ind + 1][ind + 1];
                }
                dp[ind][prev_ind + 1] = max(take,not_take);
            }
        }

        return dp[0][-1 + 1];
    }
};

class Solution {
    
    // 4.Space optimization
    // TC : O(n * n)
    // SC : O(n)

public:
   
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ahead(n+1,0) , curr(n+1,0);

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int prev_ind = n - 1; prev_ind >= -1; prev_ind--) {
                int not_take = 0 + ahead[prev_ind + 1];
 
                int take = INT_MIN;

                if(prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    take = 1 + ahead[ind + 1];
                }
                curr[prev_ind + 1] = max(take,not_take);
            }

            ahead = curr;
        }

        return curr[0];
    }
};

class Solution {
    
    // 5.Binary search
    // TC : O(n * logn)
    // SC : O(n)

public:
   
    int lengthOfLIS(vector<int>& nums) {
 
        vector<int>temp;
        temp.push_back(nums[0]);
        int len = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            }
            else {
                auto ind = lower_bound(temp.begin(), temp.end(), nums[i]);
                temp[ind - temp.begin()] = nums[i];

            }
        }

        return len;
    }
};