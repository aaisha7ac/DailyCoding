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
    string postToInfix(string exp) {
        // Write your code here
        
        stack<string>st;
        
        for(int i = 0; i < exp.length(); i++) {
            
            string s= "";
            s += exp[i];
            
            if(exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= '0' && exp[i] <= '9') {
                st.push(s);
            }
            
            else {
                string A = st.top();
                st.pop();
                string B = st.top();
                st.pop();
                st.push("(" + B + s + A + ")");
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
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends