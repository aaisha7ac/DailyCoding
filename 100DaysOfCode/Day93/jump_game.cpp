class Solution {

    // 1. Using recursion
    // TC : O(n!)
    // SC : O(n) , auxiliary stack space
public:

    bool solve(int ind,vector<int>& nums) {

        if(ind == nums.size() - 1) return true;

        for(int i = 1; i <= nums[ind]; i++) {
            if(solve(ind + i,nums) == true) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {

        return solve(0,nums);
    }
};




class Solution {

    // 2. Using memoization
    // TC : O(n)
    // SC : O(n) + O(n), auxiliary stack space and for memoization

public:

    bool solve(int ind,vector<int>& nums,vector<int>& dp) {

        if(ind == nums.size() - 1) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i = 1; i <= nums[ind]; i++) {
            if(solve(ind + i,nums,dp) == true) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};




class Solution {

    // 3. Tabulation
    // TC : O(n^2)
    // SC : O(n)

public:

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n+1,false);

        dp[0] = true; // 0th index will always be true

        for(int i = 1; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] == true && j + nums[j] >= i) {
                    dp[i] = true;
                }
            }
        }
        return dp[n-1];
    }
};



class Solution {

    // Most optimised solution
    // TC : O(n)
    // SC : O(1)
    
public:
    bool canJump(vector<int>& nums) {
        
        int maxreachable = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(i > maxreachable) {
                return false;
            }
            if(nums[i] + i > maxreachable) {
                maxreachable = nums[i] + i;
            }
        }

        return true;
    }
};