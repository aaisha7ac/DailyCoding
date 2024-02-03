class Solution {

    // Using memoization
    // TC : O(n)
    // SC : O(n) + O(n), stack space and dp vector
    
public:

    int solve(int n,vector<int>& nums,vector<int>& dp) {

        if(n == 0) {
            return nums[n];
        }

        if(n < 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int pick = nums[n] + solve(n-2,nums,dp);
        int not_pick = 0 + solve(n-1,nums,dp);

        return dp[n] = max(pick,not_pick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
        
    }
};


class Solution {

    // Using tabulation
    // TC : O(n)
    // SC : O(n) , for dp vector

public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n,0); 

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            int pick = nums[i];
            if(i > 1) {
                pick += dp[i-2];
            }

            int not_pick = 0 + dp[i-1];

            dp[i] = max(pick,not_pick);

        }

        return dp[n-1];
    }
};


class Solution {

    // Using space optimisation
    // TC : O(n)
    // SC : O(1)

public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        int prev = 0;
        int prev2 = 0;

        for(int i = 0; i < n; i++) {

            int pick = nums[i];
            if(i > 1) {
                pick += prev2;
            }

            int not_pick = 0 + prev;

            int curr = max(pick,not_pick);
            prev2 = prev;
            prev = curr;

        }

        return prev;
    }
};