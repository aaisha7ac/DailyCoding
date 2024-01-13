//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends

    // TC : O(|S|*|S|)
    // SC : O(|S|*|S|)

    int t[1001][1001];
    
    int longest_common_subsequence(string A,string B,int m,int n) {
        
        // base case or initialization
        for(int i = 0; i < m + 1; i++) {
            for(int j = 0; j < n + 1; j++) {
                if(i == 0 || j == 0) {
                    t[i][j] = 0;
                }
            }
        }
        
        
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                if(A[i-1] == B[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t[m][n];
    }
    

    int minDeletions(string str, int n) { 
    //complete the function here 
        string A = str;
        string B = str;
        reverse(B.begin(),B.end());
            
        int length_of_LCS = longest_common_subsequence(A,B,n,n);
        
        return n - length_of_LCS;
    } 