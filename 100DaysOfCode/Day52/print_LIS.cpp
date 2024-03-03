class Solution {
    
    // TC : O(n^2)
    // SC : O(2n)
    
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int>ans;
        
        vector<int>dp(n,1),hash(n);
        
        int lastindex = -1;
        
        int max_len = 0;
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            
            if(dp[i] > max_len) {
                max_len = dp[i];
                lastindex = i;
            }
        }
        
        ans.push_back(arr[lastindex]);
        
        while(hash[lastindex] != lastindex) {
            lastindex = hash[lastindex];
            ans.push_back(arr[lastindex]);
        }
        
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};