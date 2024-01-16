#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Result {
    public: int size;
            int arr[100];
            Result(int n);
           void moveElements();
           void display();
};
Result::Result(int n)
            {
                    size=n;
                    for(int t=0;t<size;t++)
                        cin>>arr[t];
            }

void Result::display()
{
        for(int t=0;t<size;t++)
            cout<<arr[t]<<endl;
}

/*
class Result {
    public: int size;
            int arr[100];
            Result(int n);
           void moveElements();
           void display();
};
*/
void Result::moveElements()
{
    // Write your code here
	for(int i = 0; i < size; i++) {
      if(arr[i] >= 0) {
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && arr[j] < 0) {
          arr[j+1] = arr[j];
          j--;
        }
        arr[j+1] = temp;
      }
    }
}

/*int main()
{
    int i, size = 0;
    scanf("%d", &size);

    int arr[size];
    for( i = 0; i < size; i++) 
        scanf("%d", &arr[i]);

    moveElements(arr, size);
    for (i = 0; i < size; i++) 
        printf("%d\n", arr[i]);
  
    return 0;
}*/

int main()
{
    int t,n,m;
    cin>>n;
    Result rt(n);
    rt.moveElements();
    rt.display();
    return 0;
}s