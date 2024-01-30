class Solution {

    // TC : O(n)
    // SC : O(1)

public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            while(nums[n-1] != n) {
                swap(nums[n-1],n);
            }
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(nums[i-1] != i) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};