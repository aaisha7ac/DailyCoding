// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int mod = 100000;
        vector<int>dist(100000,INT_MAX);
        dist[start] = 0;
        
        
        queue<pair<int,int>>q;
        
        // steps and start
        q.push({0,start});
        
        while(!q.empty()) {
            
            int dis = q.front().first;
            int node = q.front().second;
            q.pop();
            
            if(node == end) {
                return dis;
            }
            
            for(int i = 0; i < arr.size(); i++) {
                int num = (node * arr[i]) % mod;
                if(dis + 1 < dist[num]) {
                    dist[num] = dis + 1;
                    q.push({dis+1,num});
                }
            }
        }
        
        return -1;
    }
};