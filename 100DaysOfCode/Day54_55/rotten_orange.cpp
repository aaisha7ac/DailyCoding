class Solution {

    // Using breadth first search traversal technique of the graph
    // TC : O(n * m)
    // SC : O(n * m)

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        // in queue we are storing row,col and time
        queue<pair<pair<int,int>,int>>q;

        int fresh1 = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // we are finding the already rotten oranges
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }

                if(grid[i][j] == 1) {
                    fresh1++;
                }
            }
        }

        int time = 0;

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        int fresh2 = 0;

        while(!q.empty()) {
            int nrow = q.front().first.first;
            int ncol = q.front().first.second;
            int t = q.front().second;

            time = max(time,t);
            q.pop();

            // rotten orange can rott fresh orange in 4 direction
            for(int i = 0; i < 4; i++) {

                int r = nrow + drow[i];
                int c = ncol + dcol[i];

                if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1 && !vis[r][c]) {
                    vis[r][c] = 1;
                    grid[r][c] = 2;
                    q.push({{r,c},t+1});
                    fresh2++;
                }
            }
        }

        if(fresh1 != fresh2) {
            return -1;
        }

        return time;
    }
};