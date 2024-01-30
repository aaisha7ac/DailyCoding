class Solution {

    // TC : O(n)
    // SC : O(1)
    
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            
            // we will increase i until the current i points to alpha or digit
            while( !(isalpha(s[i]) || isdigit(s[i])) && i < j) {
                i++;
            }

            // we will decrease j until the current j points to alpha or digit
            while( !(isalpha(s[j]) || isdigit(s[j])) && i < j) {
                j--;
            }

            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};