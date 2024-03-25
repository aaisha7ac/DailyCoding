class Solution {
  public:
  
    // TC: O(V^2)
    // SC : O(V)
    
  
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
    
    
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        DisjointSet ds(V);
        
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1) { // edge exists between them
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < V; i++) {
            if(ds.ultimate_parent(i) == i) {
                cnt++;
            } 
        }
        
        return cnt;
    }
};