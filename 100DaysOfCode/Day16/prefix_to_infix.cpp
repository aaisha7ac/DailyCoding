//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    // TC : O(n)
    // SC : O(n)
    
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        
        stack<string>st;
        
        for(int i = pre_exp.length() - 1; i >= 0; i--) {
            
            string s = "";
            s += pre_exp[i];
            
            if(s >= "a" && s <= "z" || s >= "A" && s <= "Z" || s >= "0" && s <= "9") {
                st.push(s);
            }
            else {
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                string temp = "(" + A + s + B + ")";
                st.push(temp);
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends