class Solution {

    // Same question as subset sum equal to K
    // Space optimization
    // TC : O(ind * target)
    // SC : O(target)

public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.

        vector<bool>prev_row(k+1,0);
        vector<bool>curr_row(k+1,0);

        // base case
        prev_row[0] = curr_row[0] = true;

        if(arr[0] <= k) {
            prev_row[arr[0]] = true;
        }


        for(int index = 1; index < n; index++) {
            for(int target = 1; target <= k; target++) {
                    bool not_take = prev_row[target];
        
                    bool take = false;
                    if(arr[index] <= target) {
                        take = prev_row[target - arr[index]];
                    }

                    curr_row[target] = take | not_take;
            }

            prev_row = curr_row;
        }

        return prev_row[k];
    }


    bool canPartition(vector<int>& nums) {

        int total_sum = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++) {
            total_sum += nums[i];
        }

        //  cannot divide the array into two subsets
        if(total_sum % 2 != 0) {
            return false;
        }

        return subsetSumToK(n,total_sum/2,nums);
    }
};