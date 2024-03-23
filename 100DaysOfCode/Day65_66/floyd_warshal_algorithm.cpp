class Solution {
    
    // TC : O(n^3)
    // SC : O(1)
    
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    int n = matrix.size();
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == -1) {
	                matrix[i][j] == INT_MAX;
	            }
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    // Floyd Warshall Algorithm
	    
	    for(int via = 0; via < n; via++) {
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
	                matrix[i][j] = min(matrix[i][j],matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    // to check if negative cycle exists
	   // for(int i = 0; i < n; i++) {
	   //     if(matrix[i][i] < 0) {
	   //         cout << "Negative Cycle exists";
	   //     }
	   // }
	    
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == INT_MAX) {
	                matrix[i][j] == -1;
	            }
	        }
	    }
	    
	}
};