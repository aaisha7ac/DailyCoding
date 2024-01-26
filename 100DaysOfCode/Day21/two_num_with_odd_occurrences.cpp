//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    
    // TC : O(n)
    // SC : O(1)
    
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        
        vector<long long> ans;
        
        int X = 0;
        
        // X = XOR of two numbers with odd occurences
        for(long long i = 0; i  < N; i++) {
            X ^= Arr[i];
        }
        
        // finding the rightmost set bit
        long long cnt = X & ~ (X-1);
        
        // differentiating the nums into two groups according to the rightmost set bit
        // each group will contain one - one elements with odd occurences
        
        long long num1 = 0;
        long long num2 = 0;
        
        for(long long i = 0; i  < N; i++) {
            
            // if rightmost bit is set
            if(Arr[i] & cnt) {
                num1 ^= Arr[i];
            } // if rightmost bit is not set
            else {
                num2 ^= Arr[i];
            }
        }
        
        if(num1 < num2) {
            ans.push_back(num2);
            ans.push_back(num1);
        }
        else {
            ans.push_back(num1);
            ans.push_back(num2);
        }
        
        return ans;
    }
        
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends