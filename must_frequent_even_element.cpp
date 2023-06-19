// https://leetcode.com/problems/most-frequent-even-element/description/

class Solution {

    // TC : O(n)
    // SC : O(n)

public:
    int mostFrequentEven(vector<int>& nums) {
        
        map<int,int> mp;

        int count = 0, result = -1;

        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] % 2 == 0) {
                mp[nums[i]]++;
                if(mp[nums[i]] > count) {
                    result = nums[i];
                    count = mp[nums[i]];
                }

                else if(mp[nums[i]] == count) {
                    if(nums[i] < result) {
                        result = nums[i];
                    }
                }
            }
        }

        return result;
    }
};