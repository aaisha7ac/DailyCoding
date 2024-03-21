class Solution {

    // Using Dijkstra's algorithm
    // TC: O(E log V)
    // SC: O(V + E)

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];

        for(auto it : times) {
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>time(n+1,INT_MAX);

        time[k] = 0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

        q.push({0,k});

        while(!q.empty()) {
            int currtime = q.top().first;
            int node = q.top().second;
            q.pop();
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int t = it.second;

                if(currtime + t < time[adjNode]) {
                    time[adjNode] = currtime + t;
                    q.push({currtime+t,adjNode});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(time[i]==INT_MAX)
                return -1;
            ans = max(ans,time[i]);
        }
        return ans;
    }
};