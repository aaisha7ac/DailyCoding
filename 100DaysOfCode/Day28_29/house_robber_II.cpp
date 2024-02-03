class Solution {

    // Space optimisation
    // TC : O(n)
    // SC : O(n) , for temporary vector

public:

    int solve(vector<int>& num) {

        int n = num.size();
        int prev = 0;
        int prev2 = 0;

        for(int i = 0; i < n; i++) {

            int pick = num[i];
            if(i > 1) {
                pick += prev2;
            }

            int not_pick = 0 + prev;

            int curr = max(pick,not_pick);
            prev2 = prev;
            prev = curr;

        }

        return prev;
    }

    int rob(vector<int>& nums) {
        
        vector<int>temp1; // it does not contain 1st element
        vector<int>temp2; // it does not contain last element

        int n = nums.size();

        // for single element
        if(n == 1) {
            return nums[0];
        }
        
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                temp1.push_back(nums[i]);
            }

            if(i != n - 1) {
                temp2.push_back(nums[i]);
            }
        }

        return max(solve(temp1),solve(temp2));

    }
};