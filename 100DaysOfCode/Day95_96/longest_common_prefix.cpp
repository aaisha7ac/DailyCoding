class Solution {

    // TC : O(n^2)
    // SC : O(1)

public:

    string find_prefix(string str1,string str2) {

        int i = 0,j = 0;
        string temp = "";
        while(i < str1.length() && j < str2.length()) {
            if(str1[i] == str2[j]) {
                temp += str1[i];
            }
            else {
                break;
            }
            i++;j++;
        }

        return temp;
    }

    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 1) {
            return strs[0];
        }

        string prefix = find_prefix(strs[0],strs[1]);
        int len = prefix.length();

        for(int i = 2; i < strs.size(); i++) {
            string temp = find_prefix(strs[i],prefix);

            if(temp.size() < len) {
                len = temp.size();
                prefix = temp;
            }
        }

        return prefix;
        
    }
};



class Solution {

    // TC : (n log n + m) , n = no.of strings , m = length of shortest string
    // SC : O(1)
    
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());

        string a = strs[0];
        string b = strs[strs.size() - 1];

        int i = 0, j = 0;
        string ans = "";
        while(i < a.length() && j < b.length()) {
            if(a[i] != b[j]) {
                break;
            }
            ans += a[i];
            i++;
            j++;
        }

        return ans;
        
    }
};