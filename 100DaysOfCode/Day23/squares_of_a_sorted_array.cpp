class Solution {

    // TC : O(n)
    // SC : O(1)
    
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        int i = n - 1;

        vector<int>ans(n);

        while(low <= high) {
            if(nums[low] * nums[low] < nums[high] * nums[high]) {
                ans[i] = nums[high] * nums[high];
                high--;
            }
            else {
                ans[i] = nums[low] * nums[low];
                low++;
            }
            i--;
        }

        return ans;

    }
};