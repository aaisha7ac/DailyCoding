//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

// TC : O(|s|)
// SC : O(|s|)


int countRev (string s)
{
    // your code here
    
    stack<char>st;
    int n = s.length();
  
    if(n % 2 != 0) {
        return -1;
    }
  
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '{') {
          st.push(s[i]);
        }
        else if(!st.empty() && (s[i] == '}' && st.top() == '{')) {
          st.pop();
        }
        else {
          st.push(s[i]);
        }
    }
  
    while(!st.empty()) {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
    
        // if both squares brackets are same we need to reverse only one bracket to make it balanced [ [
        if(a == b) {
          ans += 1;
        }
    
        // if both squares brackets are different we need to reverse both bracket to make it balanced ] [
        else { 
          ans += 2;
        }
    }
  
    return ans; 
}