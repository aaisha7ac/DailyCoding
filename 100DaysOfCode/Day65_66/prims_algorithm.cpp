class Solution
{
    // Prim's Algorithm
    // TC : O(ElogE)
    // SC : O(E)
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        int sum = 0;
        
        vector<int>vis(V,0);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        // weight and node
        pq.push({0,0});
        
        
        // E
        while(!pq.empty()) {
            
            // log E
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            if(vis[node] == 1) continue;
            
            // Just mark vistied here
            vis[node] = 1;
            
            sum += wt;
            
            // E log E
            for(auto it: adj[node]) {
                
                int n = it[0];
                int w = it[1];
                
                if(!vis[n]) {
                    pq.push({w,n});
                }
            }
            
        }
        
        return sum;
    }
};