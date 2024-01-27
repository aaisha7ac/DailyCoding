//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    // TC : O(n)
    // SC : O(1)
    
  public:
    string reverseEqn (string s)
        {
            //code here.
            
            string num = "";
            string ans = "";
            
            for(int i = s.length() - 1; i >= 0; i--) {
                
                if(isdigit(s[i])) {
                    num = s[i] + num;
                }
                
                else {
                    ans = ans + num + s[i];
                    num = "";
                }
            }
            
            ans += num;
            
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends