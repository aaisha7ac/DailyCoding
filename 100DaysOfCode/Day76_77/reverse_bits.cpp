class Solution {

    // TC : O(n)
    // SC : O(1)
    
public:
    uint32_t reverseBits(uint32_t n) {


        uint32_t ans = 0;

        for(int i = 0; i <= 31; i++) {

            // check the ith bit is set or not
            uint32_t bit = n & (1 << i);

            // if ith bit is 1, setting it in reverse order in ans
            if(bit != 0) {
                ans = ans | (1 << (31 - i));
            }
        }

        return ans;
        
    }
};