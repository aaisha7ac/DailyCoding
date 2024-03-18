
class Solution
{
    // Using priority queue
    // TC : O(E log v)
    // SC : O(V + E)
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        
        vector<int>dis(V,INT_MAX);
        
        dis[S] = 0;
        
        while(!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]) {
                
                int n = it[0];
                int w = it[1];
                
                if(wt + w < dis[n]) {
                    dis[n] = wt + w;
                    pq.push({wt+w,n});
                }
                
            }
            
        }
        
        return dis;
    }
};


class Solution
{
    
    // Using set 
    // TC : O((V + E) * log V)
    // SC : O(V + E)
    
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pair<int,int>>st;
        
        vector<int>dis(V,INT_MAX);
        
        dis[S] = 0;
        
        st.insert({0,S});
        
        while(!st.empty()) {
            
            auto it = *(st.begin());
            int wt = it.first;
            int node = it.second;
            
            st.erase(it);
            
            for(auto it : adj[node]) {
                
                int n = it[0];
                int w = it[1];
                
                if(wt + w < dis[n]) {
                    
                    st.erase({w,n}); // we are erasing the exisiting distance for a particular node because we got the smaller distance
                    dis[n] = wt + w;
                    st.insert({wt+w,n});
                }
                
            }
        }
        
        return dis;
    }
};

