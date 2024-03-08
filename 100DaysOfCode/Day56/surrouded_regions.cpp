class Solution {

    // Using breadth first search traversal technique of the graph
    // TC : O(n * m)
    // SC : O(n * m)

public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        queue<pair<int,int>>q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && board[i][j] == 'O') {
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //        cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int r = row + drow[i];
                int c = col + dcol[i];

                if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && board[r][c] == 'O') {
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }

         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
               cout << vis[i][j] << " ";
            }
            cout << endl;
        }


        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};