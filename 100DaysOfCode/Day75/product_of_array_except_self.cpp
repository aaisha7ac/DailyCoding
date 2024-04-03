class Solution {

    // TC : O(n)
    // SC : O(2n)

public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int>ans(n),prefix(n),suffix(n);
        
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }

        // for(int i = 0; i < n; i++) {
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i];
        }

        // for(int i = 0; i < n; i++) {
        //     cout << suffix[i] << " ";
        // }
        // cout << endl;

        for(int i = 0; i < n; i++) {
            
            if(i == 0) {
                ans[i] = suffix[i+1];
            }
            else if(i == n - 1) {
                ans[i] = prefix[i-1];
            }
            else {
                ans[i] = prefix[i-1] * suffix[i+1];
            }
        }

        return ans;
        
    }
};




class Solution {

    // TC : O(n)
    // SC : O(1)

public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int>ans(n,1);

        int curr = 1;

        for(int i = 0; i < n; i++) {
            ans[i] = ans[i] * curr;
            curr = curr * nums[i];
        }

        curr = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * curr;
            curr = curr * nums[i];
        }

        return ans;
        
    }
};