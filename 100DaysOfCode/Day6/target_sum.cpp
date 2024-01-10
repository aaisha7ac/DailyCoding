class Solution {

    // TC : O(n * sum)
    // SC : O(n * sum)

public:
    int subsetSum(vector<int>& nums,int sum,int n) {

        int t[n+1][sum+1];

        // base or initialization 
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(i == 0) {
                    t[i][j] = 0;
                }
                if(j == 0) {
                    t[i][j] = 1;
                }
            }
        }

        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(nums[i-1] <= j) {
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // consider two subsets s1 and s2
        // s1 - s2 = target
        // s1 + s2 = sum
        // 2s1 = sum + target
        // s1 = (sum + target) / 2

        int s1 = (sum + target) / 2;


        // can't divide into two subsets || sum is less than 0 (edge case)
        if((sum + target) % 2 != 0 || s1 < 0) {
            return 0;
        }

        return subsetSum(nums,s1,n);

    }
};