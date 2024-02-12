class Solution {

    // TC : O(m * n)
    // SC : O(1)
    
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        int cnt = 0;
        int n = nums.size();
        int m = pattern.size();
        
        for(int i = 0; i < n; i++) {
            
            int check = 0;
            int k = i;
            
            for(int j = 0; j < m; j++) {
                
                if (k + 1 < n) {
                    if (pattern[j] == 1 && nums[k] < nums[k+1]) {
                        check++;
                    }
                    else if (pattern[j] == 0 && nums[k] == nums[k+1]) {
                        check++;
                    }
                    else if (pattern[j] == -1 && nums[k] > nums[k+1]) {
                        check++;
                    }
                    else {
                        break; 
                    }
                    k++;
                }
                
                else {
                    break; 
                }
                
            }
            
            if(check == m) {
                cnt++;
            }
            
        }
        
        return cnt;
    }
};