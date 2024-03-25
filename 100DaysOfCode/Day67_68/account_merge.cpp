class Solution {

    // TC :
    // SC :

public:

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


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {


        unordered_map<string,int>mapMail;
        int n = accounts.size();

        DisjointSet ds(n);

        // mapping mail with index(row)
        for(int i = 0; i < n; i++) {
            // mail starts from index 1
            for(int j = 1; j < accounts[i].size(); j++) {
                // if mail is coming for the first time, map it with index
                string mail = accounts[i][j];
                if(mapMail.find(mail) == mapMail.end()) {
                    mapMail[mail] = i;
                }
                // if same mail was occured previously, we will merge the current row index with the row where mail was occured previously
                else {
                    ds.unionBySize(i,mapMail[mail]);
                }
            } 
        }

        // merge all mail which belongs to same node
        vector<string>mergedMail[n];
        for(auto it: mapMail) {
            string mail = it.first;
            int node = ds.ultimate_parent(it.second);
            mergedMail[node].push_back(mail);
        }


        vector<vector<string>>ans;

        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]); // first push name
            for(auto it: mergedMail[i]){
                temp.push_back(it); // then push mail
            }
            ans.push_back(temp);
        }

        return ans;
        
    }
};