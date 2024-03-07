class Solution {

    // TC : O(n) + O(n + 2E)
    // SC : O(n) + O(n)
    
public:

    void dfs(int node,vector<int> &visited,vector<int> adj[]) {
        
        visited[node] = 1;

        for(auto it : adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<int>visited(V,0);

        vector<int>adj[V];

        // converting 2D adjancey matrix into adjancey list
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i,visited,adj);
            }
        }
        

        return cnt;
    }
};