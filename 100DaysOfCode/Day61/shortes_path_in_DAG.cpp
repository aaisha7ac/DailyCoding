// TC : O(V + E) + O(N + M)
// SC : O(V + E)

class Solution {
  public:
  
   void dfs(int node,vector<int> &vis,vector<pair<int,int>> adj[],stack<int> &st) {
	    
	    vis[node] = 1;
	    
	    for(auto it : adj[node]) {
	        int v = it.first;
	        if(!vis[v]) {
	            dfs(v,vis,adj,st);
	        }
	    }
	    
	    st.push(node);
	}
	
	
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges) {
        // code here
        
        // 1. Creating the adjacency list
        // storing the adjacent node and wight of the edge
        vector<pair<int,int>> adj[N];
        
        for(int i = 0; i < M; i++) {
            
            // int u = edges[i][0];
            // int v = edges[i][1];
            // int wt = edges[i][2];
            // adj[u].push_back({v , wt});
            
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        // 2. Topo sort using dfs
        
        vector<int>vis(N,0);
        
        stack<int>st;
        
        for(int i = 0; i < N; i++) {
	        if(!vis[i]) {
	            dfs(i,vis,adj,st);
	        }
	    }
	    
	    // 3. Calculating distance vector
	    vector<int>dist(N,INT_MAX);
	    dist[0] = 0;

	    
	    while(!st.empty()) {
	        int node = st.top();
	        st.pop();
	        
	        if(dist[node] != INT_MAX) {
	            
	            for(auto it : adj[node]) {
    	            int v = it.first;
    	            int wt = it.second;
    	            
    	            if(dist[node] + wt < dist[v]) {
    	                dist[v] = dist[node] + wt;
    	            }
	            }
	            
	        }
	        
	    }
	    
	    
	    for(int i = 0; i < N; i++) {
	        if(dist[i] == INT_MAX) {
	            dist[i] = -1;
	        }
	    }
	    
	    return dist;
	    
    }
};
