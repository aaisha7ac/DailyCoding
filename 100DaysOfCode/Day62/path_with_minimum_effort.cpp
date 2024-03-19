class Solution {

    // TC : O(E log V)
    // SC : O(row * col)
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;


        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        // dist,row,col
        pq.push({0,{0,0}});

        int nrow[] = {-1,0,+1,0};
        int ncol[] = {0,+1,0,-1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if(r == n-1 && c == m-1) {
                return d;
            }

            for(int i = 0; i < 4; i++) {
                int row = r + nrow[i];
                int col = c + ncol[i];

                if(row >= 0 && row < n && col >= 0 && col < m) {
                    int newEffort = max(abs(heights[r][c] - heights[row][col]),d);
                    if(newEffort < dist[row][col]) {
                        dist[row][col] = newEffort;
                        pq.push({newEffort,{row,col}});
                    }
                }
            }
        }

        return 0;
    
    }
};