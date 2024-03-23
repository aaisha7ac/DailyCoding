// User function Template for C++
class Solution {
    
    // Using Floyd Warshall Alogrithm
    // TC : O(n^3)
    // SC : O(n^2)
    
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
        
        for(auto it: edges) {
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] = it[2];
        }
        
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }
        
        for(int via = 0; via < n; via++) {
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
	                if (cost[i][via] != INT_MAX && cost[via][j] != INT_MAX) {
                        cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                    }
	            }
	        }
	    }
	    
	    int cntmax = INT_MAX;
	    int cityNo = -1;
	    
	    for(int i = 0; i < n; i++) {
	        int cnt = 0;
	        for(int j = 0; j < n; j++) {
	            if(cost[i][j] <= distanceThreshold) {
	                cnt++;
	            }
	        }
	        
	        if(cnt <= cntmax) {
	            cntmax = cnt;
	            cityNo = i;
	        }
	    }
	    
	    return cityNo;
    }
};