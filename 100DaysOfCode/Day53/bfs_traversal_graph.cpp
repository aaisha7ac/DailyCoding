class Solution {
    
    // TC : O(n) + O(2E)
    // SC : O(n)
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        
        vector<int>ans;
        
        while(!q.empty()) {
            
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it: adj[node]) {
                if(!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
            
        }
        
        return ans;
    }
};