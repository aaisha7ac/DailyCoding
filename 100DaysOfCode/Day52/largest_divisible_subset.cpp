class Solution {

    // TC : O(n^2)
    // SC : O(2n)

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        vector<int>ans;

        int n = nums.size();
        
        vector<int>dp(n,1),hash(n);
        
        int lastindex = -1;
        
        int max_len = 0;
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > max_len) {
                max_len = dp[i];
                lastindex = i;
            }
        }
        
        ans.push_back(nums[lastindex]);
        
        while(hash[lastindex] != lastindex) {
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};