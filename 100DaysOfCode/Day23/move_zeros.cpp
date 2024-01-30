class Solution {

    // TC : O(n)
    // SC : O(1)
    
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0;
        int j = 0;

        while(i < nums.size()) {
            if(nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
            i++;
        }

    }
};