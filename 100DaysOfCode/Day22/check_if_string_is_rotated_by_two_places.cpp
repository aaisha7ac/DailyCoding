//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    // TC : O(n)
    // SC : O(1)
    
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int m = str1.length();
        int n = str2.length();
        
        if(m != n || str1 == str2) {
            return false;
        }
        
        int check = 0;
        
        int i,j;
        if(str1[0] == str2[n-2] && str1[1] == str2[n-1]) {
            i = 2;
            j = 0;
            check = 1;
        }
        
        if(str2[0] == str1[m-2] && str2[1] == str1[m-1]) {
            i = 0;
            j = 2;
            check = 1;
        }
        
        if(check == 0) {
            return false;
        }
        
        while(i < n && j < n - 2) {
            if(str1[i] != str2[j]) {
                return false;
            }
            i++;
            j++;
        }
        
        return true;
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends