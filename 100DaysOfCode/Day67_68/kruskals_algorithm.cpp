class Solution
{
    
    // SC: O(V + M), M = edges
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	class DisjointSet {

        vector<int>size,parent;
    
        public:
        DisjointSet(int n){
    
            // 1 based indexing
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i <= n; i++) {
                parent[i] = i;
            }
    
        }
    
        int ultimate_parent(int node) {
    
            // base case
            if(node == parent[node]) {
                return node;
            }
    
            // path compression
            return parent[node] = ultimate_parent(parent[node]);
        }
    
    
        void unionBySize(int u,int v) {
            int ulp_u = ultimate_parent(u);
            int ulp_v = ultimate_parent(v);
    
            // if ultimate parent of u and v are equal that mean they both belong to the same component
            if(ulp_u == ulp_v) {
                return;
            }
    
            // u will be attached to v and have parent as v
            else if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
    
            // size[ulp_v] < size[ulp_u] or size[ulp_v] == size[ulp_u]
            // v will be attached to u and have parent as u and if both are equal anyone can attach to anyone
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };
    
    

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>>edges;
        
        // O(V + M)
        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                int adjnode = it[0];
                int wt = it[1];
                
                // no need to insert twice
                edges.push_back({wt,{i,adjnode}});
            }
        }
        
        // (M log M)
        sort(edges.begin(),edges.end());
        int ans = 0;
        
        DisjointSet ds(V);
        
        // O(M * 4 alpha * 2 )
        for(auto it: edges) {
            
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.ultimate_parent(u) != ds.ultimate_parent(v)) {
                ans += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return ans;
    }
};