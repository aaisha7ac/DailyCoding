class Solution {

    // TC : O(n * log(m))
    // n = number of elements in the input vector nums, m = number of unique elements in nums. 
    // The insertion operation in a set takes O(log(m)) time, and we perform it for each element in nums.

    // SC : O(m)

public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) {
            return 0;
        }

        set<int>st;

        for(int num: nums) {
            st.insert(num);
        }

        int len = 1;
        int prev_num = 0;
        int ans = INT_MIN;
        int i = 0;

        for(int num : st) {

            if(i == 0) {
                prev_num = num;
                i++;
                continue;
            }

            if(num - prev_num == 1) {
                len++;
            }

            else {
                ans = max(len,ans);
                len = 1;
            }

            prev_num = num;
        }

        ans = max(ans,len);

        return ans;
        
    }
};