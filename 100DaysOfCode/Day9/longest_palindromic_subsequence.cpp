//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    // TC : O(|S|*|S|)
    // SC : O(|S|*|S|)
    
    
  public:
  
    int t[1001][1001];
    
    int longest_common_subsequence(string A,string B,int m,int n) {
        
        // base case or initialization
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }
        
        
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(A[i-1] == B[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
    
    
    int longestPalinSubseq(string A) {
        //code here
        
        int n = A.length();
        string B = A;
        reverse(B.begin(),B.end());
        
        return longest_common_subsequence(A,B,n,n);
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends