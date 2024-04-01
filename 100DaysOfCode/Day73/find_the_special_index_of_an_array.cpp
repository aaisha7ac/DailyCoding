#include<bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(n)

int specialIndex(vector<int> arr) {
  // Write your code here
  int n = arr.size();
  vector<int>prefix_sum(n),suffix_sum(n);
  
  suffix_sum[0] = arr[0];
  prefix_sum[n-1] = arr[n-1];
  
  for(int i = 1; i < n; i++) {
    suffix_sum[i] = arr[i] + suffix_sum[i-1];
  }
  
  for(int i = n - 2; i >= 0; i--) {
    prefix_sum[i] = arr[i] + prefix_sum[i+1];
  }
  
  for(int i = 0; i < n; i++) {
      if(i == 0 && prefix_sum[i+1] == 0 || i == n - 1 && suffix_sum[i - 2] == 0 || prefix_sum[i+1] == suffix_sum[i-1]) {
          return i;
      }
  }
  
  return -1;
}

int main(){
  int t, n;
  cin>>t;
  while (t--) {
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
      cin>>arr[i];
    }
    cout<<specialIndex(arr)<<endl;
  }
  return 0;
}