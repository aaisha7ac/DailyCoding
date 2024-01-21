//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    
    // TC : O(r * c)
    // SC : O(1)
    
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        
        int sr = 0;
        int sc = 0;
        int er = r - 1;
        int ec = c - 1;
        
        vector<int>ans;     
        
        while(sr <= er && sc <= ec) {
            
            for(int i = sc; i <= ec; i++) {
                ans.push_back(matrix[sr][i]);
            }
            sr++;
            
            for(int i = sr; i <= er; i++) {
                ans.push_back(matrix[i][ec]);
            }
            ec--;
            
            if(sr <= er) {
                for(int i = ec; i >= sc; i--) {
                    ans.push_back(matrix[er][i]);
                }
                er--;
            }
          
            if(sc <= ec) {
                for(int i = er; i >= sr; i--) {
                    ans.push_back(matrix[i][sc]);
                }
                sc++;
            }
           
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends