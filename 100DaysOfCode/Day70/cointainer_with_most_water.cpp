class Solution {

    // TC : O(n)
    // SC : O(1)

public:
    int maxArea(vector<int>& height) {

        int ans = 0;
        int n = height.size();

        int i = 0;
        int j = n - 1;

        while(i < j) {
            int l = min(height[i],height[j]);
            int b = j - i;
            ans = max(ans,l * b);

            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        } 

        return ans;
        
    }
};