#include<bits/stdc++.h>
using namespace std;
class ArrayComparator {
	int *arr1,*arr2;
  	int size;
  	public:
  	ArrayComparator(int A[],int B[], int N){
      size=N;
      arr1=A;
      arr2=B;
    }
    static const int offset = 50001;  // Maximum absolute value for elements
    bool areArraysEqual() ;
};
/*
class ArrayComparator {
public:
    static const int offset = 50001;  // Maximum absolute value for elements
    bool areArraysEqual(int arr1[], int arr2[], int size) ;
};
*/
   bool ArrayComparator:: areArraysEqual()
     {
       //Write your code here
       unordered_map<int,int>mp;
	  for(int i = 0; i < size; i++) {
			mp[arr1[i]]++;
       }
     for(int i = 0; i < size; i++) {
       if(mp.find(arr2[i]) == mp.end() || mp[arr2[i]] == 0) {
         return false;
       }
       mp[arr2[i]]--;
     }
     return true;
     }


     int main() {
    int N;
    cin >> N;

    int A[N], B[N];
  	
	
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    ArrayComparator arrayComparator(A, B, N);
    int result = arrayComparator.areArraysEqual() ? 1 : 0;

    cout << result << std::endl;

    return 0;
}