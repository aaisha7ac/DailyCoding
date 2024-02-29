class Solution{
    
    // TC : O(n)
    // SC : O(n)
    
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int ans = 0;
        int sum = 0;
        unordered_map<int,int>mp;
          
        for(int i = 0; i < n; i++) {
            
            sum += A[i];
            
            if(sum == 0) {
              ans = i + 1;
            }
            else if(mp.find(sum) != mp.end()) {
              ans = max(ans,i-mp[sum]);
            }
            else {
              mp[sum] = i;
            }
        }
          
        return ans;
    }
};