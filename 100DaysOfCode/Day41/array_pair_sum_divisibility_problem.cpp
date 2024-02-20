#include <bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(n)
int isArrayDivisibleInPairs(int a[], int n, int k){
  // Write your code here
  unordered_set<int>st;
  for(int i = 0; i < n; i++) {
    int r1 = a[i] % k;
    int r2 = k - r1;
    if(st.find(r2) != st.end()) {
      st.erase(r2);
    }
    // corner case
    else if(r1 == 0 && st.find(0) != st.end()) {
      st.erase(0);
    }
    else {
      st.insert(r1);
    }
  }
  return st.size() == 0;
}

int main()
{
  int i,n, k;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
  cin>>k;
  cout<<isArrayDivisibleInPairs(a,n,k);
  return 0;
}