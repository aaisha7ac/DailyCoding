#include <iostream>
#include <vector>

using namespace std;


// TC : O(nlogn)
// SC : O(n)
// Merges two subarrays of arr[].
// First subarray is arr[low...mid] and Second subarray is arr[mid+1..high] 
void merge(vector<int>& arr, int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int ind = 0;
  vector<int>temp(high-low+1);
  while(i <= mid && j <= high) {
    if(arr[i] <= arr[j]) {
      temp[ind] = arr[i];
      i++;
    }
    else {
      temp[ind] = arr[j];
      j++;
    }
    ind++;
  }
  while(i <= mid) {
    temp[ind] = arr[i];
    ind++;
    i++;
  }
  while(j <= high) {
    temp[ind] = arr[j];
    ind++;
    j++;
  }
  ind = 0;
  for(int i = low; i <= high; i++) {
    arr[i] = temp[ind];
    ind++;
  }
}
/* low is for left index and high is for right index of the sub-array of arr to be sorted */
void mergeSort(vector<int>& arr, int low, int high){
  if(low == high) {
    return;
  }
  int mid = (low + high)/2;
  mergeSort(arr,low,mid);
  mergeSort(arr,mid+1,high);
  merge(arr,low,mid,high);
}

int main() {
	int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    } 
    // Perform merge sort on the array
   mergeSort(arr, 0, N - 1);
	// Output the sorted array
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}