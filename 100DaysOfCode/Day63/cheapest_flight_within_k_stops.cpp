class Solution {

    // TC: O(V + E) E = no of edges, flights.size()
    // SC: O(V + E)

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];

        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;

        // k , src, dist
        q.push({0,{src,0}});

        vector<int>dist(n,INT_MAX);
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stop = it.first; // stops
            int node = it.second.first;
            int dis = it.second.second;

            if(stop > k) continue; // if stop is greater than k we wont't check it's adjancey list

            for(auto itr : adj[node]) {
                int adjnode = itr.first;
                int d = itr.second;
                if(dis  + d < dist[adjnode] && stop <= k) {
                    dist[adjnode] = dis + d;
                    q.push({stop+1,{adjnode,dis + d}});
                }
            }
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }

        return dist[dst];
    }
};