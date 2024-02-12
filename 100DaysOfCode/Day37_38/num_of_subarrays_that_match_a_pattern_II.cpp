class Solution {

    // TC : O(m + n) , m = length of pattern, n = length of nums
    // SC : O(m + k) , for LPS and temp vector

public:

    void find_LPS(vector<int> &pattern,vector<int>& LPS,int m) {

        int i = 1;
        int length = 0;

        while(i < m) {
            if(pattern[i] == pattern[length]) {
                length++;
                LPS[i] = length;
                i++;
            }
            else {
                if(length > 0) {
                    length = LPS[length-1];
                }
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

    }


    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        int n = nums.size();
        int m = pattern.size();
        
        vector<int>temp(n,-1);
        
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i - 1]) temp[i - 1] = 1;
            else if(nums[i] == nums[i - 1]) temp[i - 1] = 0;
            else temp[i - 1] = -1; 
        }

        n--;
        
        vector<int>LPS(m,0);
        find_LPS(pattern,LPS,m);


        int i = 0;
        int j = 0;
        int ans = 0;

        

        while(i < n) {
            if(temp[i] == pattern[j]) {
                i++;
                j++;
            }

            if(j == m) {
                ans++;
                j = LPS[j-1];
            }

            else if(temp[i] != pattern[j]) {
                if(j > 0) {
                    j = LPS[j-1];
                }
                else {
                    i++;
                }
            }
        }
        
        return ans;
        
    }
};