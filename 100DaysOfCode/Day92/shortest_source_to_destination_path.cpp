// User function Template for C++

class Solution {
    
    // TC : O(N * M)
    // SC : O(N * M)
    
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        // base case
        if(A[0][0] == 0) return -1;
        
        if(X == 0 && Y == 0) return 0;
        
        queue<pair<pair<int,int>,int>>q;
        
        vector<vector<int>>vis(N,vector<int>(M,0));
        
        q.push({{0,0},0});
        vis[0][0] = 1;
        
        int row[] = {0,0,-1,+1};
        int col[] = {-1,+1,0,0};
        
        // int ans = INT_MAX;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int steps = it.second;
            
            for(int i = 0; i < 4; i++) {
                int nr = r + row[i];
                int nc = c + col[i];
                
                
                if(nr >= 0 && nr < N && nc >= 0 && nc < M && A[nr][nc] == 1 && vis[nr][nc] != 1) {
                    
                    if(nr == X && nc == Y) {
                        // ans = min(ans,steps+1);
                        // return ans;
                        return steps + 1;
                    }
                    
                    vis[nr][nc] = 1;
                    q.push({{nr,nc},steps+1});
                }
                
            }
            
        }
        
        // if(ans == INT_MAX) return -1;
        
        // return ans;
        
        return -1;
    }
};