class Solution {
    
    // TC : O(V + 2E)
    // SC : O(E)
    
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int>adj[N];
        
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>dis(N,INT_MAX);
        dis[src] = 0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()) {
            
            int node = q.front();
            
            q.pop();
            
            for(auto it: adj[node]) {
                if(dis[node] + 1 < dis[it]) {
                    dis[it] = dis[node] + 1;
                    q.push(it);
                }
            }
        }
        
        for(int i = 0; i < N; i++) {
            if(dis[i] == INT_MAX) {
                dis[i] = -1;
            }
        }
        
        return dis;
    }