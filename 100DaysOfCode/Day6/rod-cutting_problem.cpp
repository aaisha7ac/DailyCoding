//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    // Unbounded knapsack
    // TC : O(n * n)
    // SC : O(n * n)
    
    int t[1001][1001];
    
public:
    int cutRod(int price[], int n) {
        //code here
        
        int length[n]; 
        // length array value from 1 to n
        for(int i = 1; i <= n; i++) {
            length[i-1] = i;
        }
        
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++) { // compare it as weight
            for(int j = 1; j < n + 1; j++) {  // compare it as weight array
                if(length[i-1] <= j) {
                    t[i][j] = max(price[i-1] + t[i][j-length[i-1]],t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        
        return t[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends