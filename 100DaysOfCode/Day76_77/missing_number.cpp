class Solution {

    // TC : O(n)
    // SC : O(1)

public:
    int missingNumber(vector<int>& nums) {


        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ i ^ nums[i];
        }

        return ans;
        
    }
};