
class Solution {
    
    // TC : O(n * m)
    // SC : O(n * m)
    
  public:
    // Function to find the number of islands.
    
    
    void bfs(int row,int col,int n,int m,vector<vector<char>> &grid,vector<vector<int>> &visited) {
        
        visited[row][col] = 1;
        
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty()) {
            
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            
            
            // we are traversing the neighbours
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    
                    int nrow = i + r;
                    int ncol = j + c;
                    
                    // should be in bound, should not be visited and it should be islands
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == '1') {
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                        
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int cnt = 0;
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                // it should not be visited and should be island
                if(!visited[row][col] && grid[row][col] == '1') {
                    
                    cnt++;
                    
                    // traversing all other connected island to it using breadth-frist search
                    bfs(row,col,n,m,grid,visited);
                    
                }
            }
        }
        
        return cnt;
    }
};