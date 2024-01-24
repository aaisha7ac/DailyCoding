class Solution {

    // Using XOR
    // TC : O(n)
    // SC : O(1)

public:
    int singleNumber(vector<int>& nums) {
        
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }

        return ans;
    }
};