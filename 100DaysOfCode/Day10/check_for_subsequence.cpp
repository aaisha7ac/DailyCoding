//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

// } Driver Code Ends

class Solution{
    
    // TC : O(n)
    // SC : O(1)
    
    public:
    bool isSubSequence(string A, string B) 
    {
        // code here
        
        int len1 = A.length();
        int len2 = B.length();
        int j = 0;
        
        for(int i = 0; i < len2; i++) {
            if(B[i] == A[j]) {
                j++;
            }
        }
        
        if(j == len1) {
            return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 

// } Driver Code Ends