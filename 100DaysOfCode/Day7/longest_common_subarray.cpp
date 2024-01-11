class Solution {

    // Subarray --> continuous common integer in the given two array

    // Using top down dp
    // TC : 0(m * n)
    // SC : 0(m * n)

    int t[1001][1001];

public:

    int longestSubarray(vector<int>& nums1, vector<int>& nums2,int m,int n) {


        // base case or initialization
        // if size of vector nums1 or nums2 is 0, it is not possible to form any subsarray

        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }


        int ans = 0;
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(nums1[i-1] == nums2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    ans = max(ans,t[i][j]);
                }
                else {
                    t[i][j] = 0;
                }
            }
        }

        return ans;
    }


    int findLength(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        return longestSubarray(nums1,nums2,m,n);
        
    }
};