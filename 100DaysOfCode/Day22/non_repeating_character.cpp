//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    
    // TC : O(|s|)
    // SC : O(|s|)
    
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
        char ans = '$';
        int hash[26] = {0};
        
        for(int i = 0; i < S.length(); i++) {
           hash[S[i] - 'a']++;
        }
        
        for(int i = 0; i < S.length(); i++) {
            if(hash[S[i] - 'a'] == 1) {
                ans = S[i];
                break;
            }
        }
        
        return ans;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends