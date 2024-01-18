//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

// TC : O(n^2)
// SC : O(n)

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        
        vector<int>hash(leaves+1,0);
        
        for(int i = 0; i < N; i++) {
            if(frogs[i] <= leaves && hash[frogs[i]] == 0) {
                for(int j = frogs[i]; j <= leaves; j+= frogs[i]) {
                    hash[j] = 1;
                }
            }
        }
        
        int count = 0;
        
        for(int i = 1; i <= leaves; i++) {
            if(hash[i] == 0) {
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends