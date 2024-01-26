//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Using bitwise operation
    
    // TC : O(n)
    // SC : O(1)
    
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        vector<int> ans;
        
        int X = 0;
        
        // X = XOR of two distinct integer in the given nums vector
        for(int i = 0; i  < nums.size(); i++) {
            X ^= nums[i];
        }
        
        // finding the rightmost set bit
        // int cnt = 0;
        
        // while(X != 0) {
            
        //     if(X & 1) {
        //         break;
        //     }
            
        //     cnt++;
        //     X = X >> 1;
        // }
        
        
        // finding the rightmost set bit
        int  cnt = X & ~ (X-1);
        
        // differentiating the nums into two groups according to the rightmost set bit
        // each group will contain one - one distinct elements
        
        // nums = {1, 2, 3, 2, 1, 4}
        // num1 = 2 2 4
        // num2 = 1 3 1

        
        int num1 = 0;
        int num2 = 0;
        
        for(int i = 0; i  < nums.size(); i++) {
            
            // if rightmost bit is set
            if(nums[i] & cnt) {
                num1 ^= nums[i];
            } // // if rightmost bit is not set
            else {
                num2 ^= nums[i];
            }
        }
        
        
        if(num1 < num2) {
            ans.push_back(num1);
            ans.push_back(num2);
        }
        else {
            ans.push_back(num2);
            ans.push_back(num1);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends