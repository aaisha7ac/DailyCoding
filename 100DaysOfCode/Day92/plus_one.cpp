class Solution {

    // TC : O(n)
    // SC : O(1)

public:
    vector<int> plusOne(vector<int>& digits) {

        int c = 0,sum;

        vector<int>ans;

        int n = digits.size() - 1;

        while(n >= 0) {
                if(n == digits.size() - 1) {
                    sum = digits[n] +  1 + c;
                }
                else {
                   sum = digits[n] + c; 
                }
                ans.push_back(sum % 10);
                c = sum / 10;
                n--;
        }

        if(c != 0) {
            ans.push_back(c);
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};