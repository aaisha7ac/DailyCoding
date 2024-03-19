class Solution {
    
    // Using Dijkstra's algorithm
    // TC : O(E log V) 
    // SC : O(V+E)
    
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        
        vector<pair<int,int>>adj[n+1];
        
        for(auto it: edges) {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        
        vector<int>dist(n+1,INT_MAX);
        dist[1] = 0;
        
        vector<int>parent(n+1);
        
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        // in priority queue we are pushing dist and the source node
        pq.push({0,1});
        
        while(!pq.empty()) {
            
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int node = it.second;
            
            for(auto it : adj[node]) {
                
                int n = it.first;
                int wt = it.second;
                if(w + wt < dist[n]) {
                    dist[n] = w + wt;
                    pq.push({w+wt,n});
                    parent[n] = node;
                }
            }
        }
        
        // if path doesn't exist then dist of n will contain INT_MAX 
        if(dist[n] == INT_MAX) {
            return {-1};
        }
        

        int node = n;
        vector<int>path;
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        path.push_back(dist[n]);
        
        reverse(path.begin(),path.end());
        return path;
        
    }
};