class Solution {
    
    // TC : O(V + 2E)
    // SC : O(3V)
    
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node,vector<int> &visited,vector<int> adj[],vector<int> &ans) {
        
        visited[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node]) {
            if(!visited[it]) {
                dfs(it,visited,adj,ans);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        vector<int>ans;
        
        int start = 0;
        
        dfs(start,visited,adj,ans);
        
        return ans;
    }
};