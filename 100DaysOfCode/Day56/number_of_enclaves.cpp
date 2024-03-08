class Solution {

    // Using breadth first search traversal technique of the graph
    // TC : O(n * m)
    // SC : O(n * m)
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
             
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // all the 1's at the boundary are marked as visited
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }


        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            // traversing all the connected 1's
            for(int i = 0; i < 4; i++) {

                int r = row + drow[i];
                int c = col + dcol[i];

                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] &&  grid[r][c] == 1) {
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};