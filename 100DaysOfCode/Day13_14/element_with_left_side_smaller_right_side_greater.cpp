//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

// TC : O(n)
// SC : O(n)

int findElement(int arr[], int n) {
    
    
    int rightsmallest[n];
    int leftlargest[n];
   
   
    int min_val = arr[n-1];
    rightsmallest[n-1] = min_val;
   
    for(int i = n - 2; i >= 0; i--) {
       min_val = min(arr[i],min_val);
       rightsmallest[i] = min_val;
    }
    
    
    int max_val = arr[0];
    leftlargest[0] = max_val;
    for(int i = 1; i < n; i++) {
        max_val = max(arr[i],max_val);
        leftlargest[i] = max_val;
    }
    
    // extreme left or right elements cannot be required element
    for(int i = 1; i <= n - 2; i++) {
        if(rightsmallest[i] == leftlargest[i]) {
            return arr[i];
        }
    }
    
    return -1;
}