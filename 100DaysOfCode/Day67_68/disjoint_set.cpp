// Implementing disjoint set using union by rank
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {

    vector<int>rank,parent;

    public:
    DisjointSet(int n){

        // 1 based indexing
        rank.resize(n+1,0);
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


    void unionByRank(int u,int v) {
        int ulp_u = ultimate_parent(u);
        int ulp_v = ultimate_parent(v);

        // if ultimate parent of u and v are equal that mean they both belong to the same component
        if(ulp_u == ulp_v) {
            return;
        }
        // u will be attached to v and have parent as v
        else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        // v will be attached to u and have parent as u
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        // if both are equal anyone can attach to anyone
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;

        }
    }
};

int main() {

    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.ultimate_parent(3) == ds.ultimate_parent(7)) {
        cout << "Belongs to the same component" << endl;
    }
    else {
        cout << "Doesn't belong to the same component" << endl;
    }

    ds.unionByRank(3,7);

    if(ds.ultimate_parent(3) == ds.ultimate_parent(7)) {
        cout << "Belongs to the same component" << endl;
    }
    else {
        cout << "Doesn't belong to the same component";
    }

    return 0;
}



// Implementing disjoint set using union by size
#include<bits/stdc++.h>
using namespace std;

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

int main() {

    DisjointSet ds(7);
    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    if(ds.ultimate_parent(3) == ds.ultimate_parent(7)) {
        cout << "Belongs to the same component" << endl;
    }
    else {
        cout << "Doesn't belong to the same component" << endl;
    }

    ds.unionBySize(3,7);

    if(ds.ultimate_parent(3) == ds.ultimate_parent(7)) {
        cout << "Belongs to the same component" << endl;
    }
    else {
        cout << "Doesn't belong to the same component";
    }

    return 0;
}