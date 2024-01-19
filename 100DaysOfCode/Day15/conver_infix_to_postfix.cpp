//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    // TC : O(n)
    // SC : O(n) , for stack
    
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int precedence(char op) {
        
        if(op == '^') {
            return 3;
        }
        else if(op == '*' || op == '/') {
            return 2;
        }
        else if(op == '+' || op == '-'){
            return 1;
        }
        else {
            return -1;
        }
        
    }
    
    
    string infixToPostfix(string s) {
        
        string ans = "";
        stack<char>st;
        
        for(int i = 0; i < s.length(); i++) {
            
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') {
                ans += s[i];
            }
            
            else if( s[i] == '(' ) {
                st.push(s[i]);
            }
            
            else if( s[i] == ')' ) {
                
                while(st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                
                st.pop(); 
            }
            
            else {
                
                while (!st.empty() && precedence(s[i]) <= precedence(st.top()) ) {
                    ans += st.top();
                    st.pop();
                }
                
                st.push(s[i]);
            }
            
        }
        
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends