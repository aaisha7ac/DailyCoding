class Solution 
{
    
    // TC : O(n * m)
    // SC : O(n * m)
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>mat)
	{
	    // Code here
	    int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        vector<vector<int>>ans(n,vector<int>(m,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }

        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,+1,0,-1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;

            int dis = q.front().second;

            q.pop();

            ans[row][col] = dis;

            for(int i = 0; i < 4; i++) {

                int r = row + drow[i];
                int c = col + dcol[i];

                if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c]) {
                    q.push({{r,c},dis+1});
                    vis[r][c] = 1;
                }
            }
        }

        return ans;
	    
	}
};