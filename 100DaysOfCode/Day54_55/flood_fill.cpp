class Solution {

    // Using breadth first search traversal technique of the graph
    // TC : O(n * m)
    // SC : O(n * m)

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        int intital_color = image[sr][sc];

        queue<pair<int,int>>q;

        q.push({sr,sc});

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            if(image[row][col] == intital_color && !vis[row][col]) {
                vis[row][col] = 1;
                image[row][col] = color;
            }

            if(row + 1 < n && image[row+1][col] == intital_color && !vis[row+1][col]) {
                vis[row+1][col] = 1;
                q.push({row+1,col});
                image[row+1][col] = color;
            }

            if(row - 1 >= 0 &&image[row-1][col] == intital_color && !vis[row-1][col]) {
                vis[row-1][col] = 1;
                q.push({row-1,col});
                image[row-1][col] = color;
            }

            if(col + 1 < m && image[row][col+1] == intital_color && !vis[row][col+1]) {
                vis[row][col+1] = 1;
                q.push({row,col+1});
                image[row][col+1] = color;
            }

            if(col - 1 >= 0 && image[row][col-1] == intital_color && !vis[row][col-1]) {
                vis[row][col-1] = 1;
                q.push({row,col-1});
                image[row][col-1] = color;
            }




        }

        return image;
    }
};