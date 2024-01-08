//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    // TC : O(N * sum)
    // SC : O(N * sum)
public:

    // same code as subset sum
    bool subsetSum(int arr[],int N,int sum) {
        
        bool t[N + 1][sum + 1];
        for(int i = 0; i < N + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(i == 0) {
                    t[i][j] = false;
                }
                if(j == 0) {
                    t[i][j] = true;
                }
            }
        }
        
        
        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < sum + 1; j++) {

                if(arr[i-1] <= j) {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        
        return t[N][sum];
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += arr[i];
        }
        
        
        // if total sum of the array is odd then it is not possible to make equal sum partition
        if(sum % 2 != 0) {
            return 0;
        }
        
        else {
            return subsetSum(arr,N,sum/2);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends