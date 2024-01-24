class Solution {

    // TC : O(1)
    // SC : O(1)

public:
    bool isPowerOfTwo(int n) {
        
        if(n == 0 || n < 0) {
            return false;
        }

        if((n & n - 1) == 0 ) {
            return true;
        }

        return false;
    }
};