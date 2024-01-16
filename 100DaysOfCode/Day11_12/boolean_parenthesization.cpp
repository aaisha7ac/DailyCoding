//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// Using memoization

// i and j will always points to T or F
// k will always points to operators

class Solution{
    
    unordered_map<string,int>mp; // same as 3D matrix containing i , j and istrue value
    
public:
    
   int solve(string s,int i,int j,bool istrue) {
        
        // base case
        
        if(i > j) { // string is empty
            return 0;
        }
        
        if(i == j) { // single element is present in the string
            if(istrue == true) {
                return s[i] == 'T';
            }
            else {
                return s[i] == 'F';
            }
        }
        
        
        string temp = to_string(i);
        temp.push_back(' ');
        temp.append(to_string(j));
        temp.push_back(' ');
        temp.append(to_string(istrue));
        
        if(mp.find(temp) != mp.end()) {
            return mp[temp];
        }
        
        
        int ways = 0;
        
        for(int k = i + 1; k <= j - 1; k+=2) {
            
            int left_T = solve(s,i,k-1,true);
            int left_F = solve(s,i,k-1,false);
            
            int right_T = solve(s,k+1,j,true);
            int right_F = solve(s,k+1,j,false);
            
            if(s[k] == '&') {
                if(istrue == true) {
                    ways = ways + left_T * right_T;
                }
                else {
                    ways = ways + left_T * right_F + left_F * right_T + left_F * right_F;
                }
            }
            
            if(s[k] == '|') {
                if(istrue == true) {
                    ways = ways + left_T * right_T + left_T * right_F + left_F * right_T ;
                }
                else {
                    ways = ways + left_F * right_F;
                }
            }
            
            if(s[k] == '^') {
                if(istrue == true) {
                    ways = ways + left_T * right_F + left_F * right_T;
                }
                else {
                    ways = ways + left_T * right_T + left_F * right_F;
                }
            }
            
        }
        
        return mp[temp] = (ways % 1003);
    }


    int countWays(int N, string S){
        // code here
        int ans = solve(S,0,N-1,true);
        return ans % 1003;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends