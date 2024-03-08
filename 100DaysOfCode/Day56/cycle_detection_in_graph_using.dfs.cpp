class Solution {
    
    // Using dfs traversal
    // TC : O(n + 2E) + O(n)
    // SC : O(n)
    
    public:
    // Function to detect cycle in an undirected graph.
    
    bool detectCycle(int node,int parent,vector<int> &visited,vector<int> adj[]) {
        
        visited[node] = 1;
        
        for(auto it : adj[node]) {
            
            if(!visited[it]) {
                if(detectCycle(it,node,visited,adj) == true) {
                    return true;
                }
            }
            else if (it != parent) {
                    return true;
            }
        }
        
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>visited(V,0);
        
        // in case if graph is broken into multiple components
        for(int i = 0; i < V; i++) {
            
                if(!visited[i]) {
                    if(detectCycle(i,-1,visited,adj) == true) {
                        return true;
                    }
                }
        }
        
        return false;
    }
};
