class Solution {

    // TC : O(max(m,n)) , m and n length of string a and b
    // SC : O(1)
public:
    string addBinary(string a, string b) {

        int i = a.length() - 1;
        int j = b.length() - 1;

        int carry = 0;

        string ans = "";

        while(i >=  0 || j >= 0 || carry) {

            if(i >= 0) {
                carry += (a[i] - '0');
            }


            if(j >= 0) {
                carry += (b[j] - '0');
            }

            ans += to_string(carry % 2);

            carry = carry/2;

            i--;
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};