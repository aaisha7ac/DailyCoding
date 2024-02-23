#include <bits/stdc++.h>
using namespace std;

// Return true if a pair with the sum k is found, else return false
// TC : O(n)
// SC : O(1)
bool pairSum(int arr[], int n, int k) {
  // Write your code here
  int low = 0;
  int high = n - 1;
  while(low < high) {
    int sum = arr[low] + arr[high];
    if(sum == k) {
      return true;
    }
    else if(sum < k) {
      low++;
    }
    else {
      high--;
    }
  }
  return false;
}

int main()
{
  int t;
  cin >> t;
  while (t--) {
    int i,n, k;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
      cin>>a[i];
    cin>>k;
    if (pairSum(a,n,k))
      cout << "Found\n";
    else
      cout << "Not Found\n";
  }
  return 0;
}
