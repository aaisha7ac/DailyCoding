//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    
    // TC : O(m * n)
    // SC : O(m * n)
    
    public:
    //Function to find length of shortest common supersequence of two strings
    
    int t[101][101];
    
    
    int longest_common_subsequence(string X, string Y, int m, int n) {
        
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }
        
        
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(X[i-1] == Y[j-1]) {
                   t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
    
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        int lenght_of_LCS = longest_common_subsequence(X,Y,m,n);

        return (m + n) - lenght_of_LCS;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends