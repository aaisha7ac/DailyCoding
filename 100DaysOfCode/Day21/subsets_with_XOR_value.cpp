//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    
    // TC : O(2^n)
    // SC : O(n)
    
public:

    int subsets(vector<int> &arr, int X, int i, int N, int K) {
        
        if(i == N) {
            if(X == K) {
                return 1;
            }
            else {
                return 0;
            }
        }
        
        int a = subsets(arr,X^arr[i],i+1,N,K);
        
        int b = subsets(arr,X,i+1,N,K);
        
        return a + b;
    }
    
    
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        
        return subsets(arr,0,0,N,K);
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends