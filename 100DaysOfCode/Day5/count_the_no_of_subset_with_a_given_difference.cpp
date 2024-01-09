#include <bits/stdc++.h> 
    // TC : O(n * sum)
    // SC : O(n * sum)

int subsetsum(vector<int> &arr,int sum,int n) {
     
 // base case or initialization
        int t[n+1][sum+1];
        int mod= (int)1e9+7;
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(i == 0) {
                    t[i][j] = 0;
                }
                
                if(j == 0) {
                    t[i][j] = 1;
                }
            }
        }
        
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < sum + 1; j++) { // sum can be zero ,as we are returning the counts we have to consider it, that's why j starts from zero
                if(arr[i-1] <= j) {
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % mod;
                }
                else {
                    t[i][j] = (t[i-1][j]) % mod;
                }
            }
            
        }
        
        return t[n][sum];
}


int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // s1 - s2 = diff
    // s1 + s2 = sum
    // s1 = (sum + diff) / 2;

      
    if((sum + d) % 2 != 0) return 0;
    
    int s1 = (sum + d) / 2;
    return subsetsum(arr,s1,n);
}


