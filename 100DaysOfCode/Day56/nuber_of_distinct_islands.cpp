class Solution {
    
    // Using dfs traversal
    //        loop    set         dfs
    // TC : O(n * m * log(n*m)) + O(n * m *4)
    // SC : O(n * m)
  public:
  
    void dfs(int row,int col,int b_row,int b_col,vector<pair<int,int>>& temp,vector<vector<int>>& vis,vector<vector<int>>& grid,int n,int m) {
        
        vis[row][col] = 1;
        
        temp.push_back({row - b_row,col - b_col}); 
        
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};
        
        // traversing in all 4 directions
        for(int i = 0; i < 4; i++) {
            
            int r = row + drow[i];
            int c = col + dcol[i];
            
            
            if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] == 1) {
                dfs(r,c,b_row,b_col,temp,vis,grid,n,m);
            }
        }
        
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                vector<pair<int,int>>temp;
                
                // it will traverse all the connected islands
                if(!vis[i][j] && grid[i][j] == 1) {
                    dfs(i,j,i,j,temp,vis,grid,n,m);
                    st.insert(temp);
                }
                
            }
        }
        
        return st.size();
    }
};