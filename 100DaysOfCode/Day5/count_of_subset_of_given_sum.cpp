//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    
    // TC : O(n * sum)
    // SC : O(n * sum)

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        // base case or initialization
        int t[n+1][sum+1];
        int mod= (int)1e9+7;
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(i == 0) {
                    t[i][j] = 0;
                }
                
                if(j == 0) {
                    t[i][j] = 1;
                }
            }
        }
        
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) { // sum can be zero ,as we are returning the counts we have to consider it, that's why j starts from zero
                if(arr[i-1] <= j) {
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
                }
                else {
                    t[i][j] = (t[i-1][j]) % mod;
                }
            }
            
        }
        
        return t[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends