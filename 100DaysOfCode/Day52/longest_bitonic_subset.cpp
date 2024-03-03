// TC : O(n^2)
// SC : O(2n)

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int>dp1(n,1),dp2(n,1);
	
	for(int i = 0; i < n; i++) {
	    for(int prev = 0; prev < i; prev++) {
	        if(arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i]) {
	            dp1[i] = 1 + dp1[prev];
	        }
	    }
	}
	
	for(int i = n - 1; i >= 0; i--) {
	   for(int prev = n - 1; prev > i; prev--) {
	       if(arr[prev] < arr[i] && 1 + dp2[prev] > dp2[i]) {
	           dp2[i] = 1 + dp2[prev];
	        }
	    }
	}
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
	    ans = max(ans,dp1[i] + dp2[i] - 1);
	}
	
	return ans;
}
