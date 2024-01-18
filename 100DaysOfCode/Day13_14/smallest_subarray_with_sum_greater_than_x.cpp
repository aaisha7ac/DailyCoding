//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    
    // TC : O(n)
    // SC : O(1)
    
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int i = 0, j = 0;
        int sum = 0;
        int ans = INT_MAX;
        
        while(i < n) {
            
            sum += arr[i];
            
            while(sum > x) {
                    ans = min(ans,i-j+1);
                    sum -= arr[j];
                    j++;
            }
            
            i++;
        }
        
        if(ans == INT_MAX) {
            return 0;
        }
        else {
            return ans;
        }
        
        
     
    }
};


//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends