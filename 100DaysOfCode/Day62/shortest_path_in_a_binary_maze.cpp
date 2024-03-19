class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();

        // base case
        
        if(n == 1 && grid[0][0] == 0) {
            return 1;
        }
        
        if(grid[0][0] == 1) {
            return -1;
        }

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        
        dist[0][0] = 0;
        
        queue<pair<int,pair<int,int>>>q;
        
        q.push({1,{0,0}});
        
        int nrow[] = {-1,-1,0,1,1,1,0,-1};
        int ncol[] = {0,1,1,1,0,-1,-1,-1};
        
        while(!q.empty()) {
            
            auto it = q.front();
            
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            q.pop();
            
            for(int i = 0; i < 8; i++) {
                
                int row = r + nrow[i];
                int col = c + ncol[i];
                
                if(row >= 0 && row < n && col >= 0 && col < n && d + 1 < dist[row][col] && grid[row][col] == 0) {
                    dist[row][col] = 1 + d;
                    if(row  == n - 1 && col == n - 1) {
                        return 1 + d;
                    }
                    q.push({d + 1,{row,col}});
                }
            }
            
        }
        
        return -1;
    }
};