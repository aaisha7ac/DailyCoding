// Brute force
// TC : O(n^2)
// SC : O(1)

#include<bits/stdc++.h>
using namespace std;
int main()
{

  string str;
  cin >> str;
  int k;
  cin >> k;
  
  int ans = INT_MIN;
  int n = str.length();
  for(int i = 0; i < n; i++) {
      
        int len = 0;
        int count = 0;
        for(int j = i; j < n; j++) {
          
            if(str[j] == '0') {
              count++;
            }
            
            
            len++;
            
            if(count > k) {
                break;
            }
        }
        
        ans = max(ans,len-1);
        
  }
  cout << ans;
  return 0;
}

// Optimized solution
// TC : O(n)
// SC : O(1)


#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
   
    int i = 0, j = 0;
   
    int ans = INT_MIN;
    int count_of_zeros = 0;
   
   while(i < s.length()) {
       
        if(s[i] == '0') {
            count_of_zeros++;
        }
       
        if(count_of_zeros > k) {
            ans = max(ans,i - j);
            while(count_of_zeros > k) {
                if(s[j] == '0') {
                   count_of_zeros--;
                }
                j++;
            }
        }
       
        i++;
    }
   
    cout << ans;

    return 0;
}