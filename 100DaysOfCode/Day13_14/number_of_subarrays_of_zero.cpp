//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// TC : O(n)
// SC : O(1)


long long int no_of_subarrays(int n, vector<int> &arr) {
    // Write your code here.
    
    long long ans = 0;
    
    // it will keep track of the continuous zeros
    long long zeros = 0;
    
    
    for(int i = 0; i < n; i++) {
        
        if(arr[i] == 0) {
            zeros++;
        }
        
        if((arr[i] == 1 && zeros != 0) || (i == n - 1 && zeros != 0)) {
            if(zeros == 1) {
                ans += zeros;
            }
            else {
                ans = ans +  (zeros * (zeros + 1) / 2); 
            }
            zeros = 0;
        }
        
    }
    

    
    return ans;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends