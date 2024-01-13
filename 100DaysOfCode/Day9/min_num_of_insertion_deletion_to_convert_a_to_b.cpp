//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	
	// TC : O(m * n)
	// SC : O(m * n)
	
	
	int t[1001][1001];
	
	int longest_common_subsequence(string str1, string str2,int m,int n) {
	    
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
	            if(str1[i-1] == str2[j-1]) {
	                t[i][j] = 1 + t[i-1][j-1];
	            }
	            else {
	                t[i][j] = max(t[i-1][j],t[i][j-1]);
	            }
	        }
	    }
	    
	    
	    return t[m][n];
	}
	
	
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.length();
	    int n = str2.length();
	    
	    int length_of_LCS = longest_common_subsequence(str1,str2,m,n);
	    
	    int no_of_deletion = m - length_of_LCS;
	    int no_of_insertion = n - length_of_LCS;
	    
	    
	    return no_of_deletion + no_of_insertion;
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends