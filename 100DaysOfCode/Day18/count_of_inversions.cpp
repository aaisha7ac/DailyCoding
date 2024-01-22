//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    
    // TC : O(nlogn)
    // SC : O(n)
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int count = 0;
    
    void merge(long long arr[],long long s,long long e) {
        
        long long mid = (s + e) / 2;
        long long i = s;
        long long j = mid + 1;
        
        vector<long long> temp;
        
        while(i <= mid && j <= e) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else { // arr[i] > arr[j]
            
            // if any element in the left array (s to mid) > than element in the right array(mid + 1,e)
            // then all element right to that element in the left array will also form pair with element in the right array
            
            // [2,3,5, 6]     [2,     4, 8]
            // s       mid    mid + 1    e
            
            
            // 3 > 2 so 5 and 6 will also form the pair (3,2) (5,2) (6,2)
            // 5 > 4 so 6 will also form pair with 4 (5,4) (6,4)
         
                count += (mid - i) + 1;
                temp.push_back(arr[j]);
                j++;
            }

        }
        
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= e) {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(long long k = s; k <= e; k++) {
            arr[k] = temp[k - s];
        }
        
    }
    
    
    void mergeSort(long long arr[],long long s,long long e) {
        
        // base case
        if(s == e) {
            return;
        }
        
        long long mid = (s + e) / 2;
        
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        
        merge(arr,s,e);
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        
        mergeSort(arr,0,N-1);
        
        return count;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends