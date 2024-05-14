class Solution {

    // TC : O(n log n)
    // SC : O(1)
    
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int i = 0, j = 0;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>ans;

        while(i < nums1.size() && j < nums2.size()) {

            if(i != 0 && nums1[i] == nums1[i-1]) {
                i++;
                continue;
            }

            if(nums1[i] < nums2[j]) {
                i++;
            }

            else if(nums1[i] > nums2[j]) {
                j++;
            }

            else {
                ans.push_back(nums1[i]);
                i++;j++;
            }
        }

        return ans;
        
    }
};