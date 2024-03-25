class Solution {

    // TC : O(n^2)
    // SC : O(n)

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


public:
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        DisjointSet ds(n);

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unionBySize(i,j);
                }
            }
        }


        for(int i = 0; i < n; i++) {
            if(ds.ultimate_parent(i) == i) {
                cnt++;
            }
        }

        return n - cnt;
    }
};