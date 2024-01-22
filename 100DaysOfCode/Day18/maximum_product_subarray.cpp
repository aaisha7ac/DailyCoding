//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    
    // TC : O(n^2)
    // SC : O(1)
    
    
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    long long ans = INT_MIN;
	    
	    for(int i = 0; i < n; i++) {
	        long long product = 1;
	        for(int j = i; j < n; j++) {
	            product *= arr[j];
	            ans = max(ans,product);
	        }
	    }
	    
	    return ans;
	    

	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends