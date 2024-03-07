class Solution {
    
    // TC : O(n + 2E) + O(n)
    // SC : O(n)
    
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detectCycle(int node,vector<int> &visited,vector<int> adj[]) {
        
        visited[node] = 1;
        
        // it will store the current node and node from where current node came (parent node)
        queue<pair<int,int>>q;
        
        q.push({node,-1});
        
        while(!q.empty()) {
            
            int curr = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            
            // travesing the adjacent node
            for(auto it : adj[curr]) {
                
                // when node is not visited
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push({it,curr});
                }
                
                // when node(it) is already visited and it is not the parent node of the current node that means loop exists
                else if(it != parent) {
                    return true;
                }
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
                bool ans = detectCycle(i,visited,adj);
                if(ans == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
};