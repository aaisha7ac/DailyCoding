// Using recursion ----> TLE
// class Solution
// {
    
//     // TC : O(2^n)
//     // SC : O(n) , auxiliary
    
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int knapSack(int W, int wt[], int val[], int n) 
//     { 
//        // Your code here
//        // base case -- no space left in the bag to keep items or no items are left to rob
//     	if(n == 0 || W == 0) {
//     		return 0;
//     	}


//     	// if weight is less than or equal to maxWeight then we have two choices to pick it or leave it
//     	if(wt[n-1] <= W) {
    
//     		return max(val[n-1] + knapSack(W-wt[n-1],wt,val,n-1),0 + knapSack(W,wt,val,n-1));
//     	}
    
//     	// if weight is more than maxWeight no choice to pick it up, leave the item and move to next one
//     	else if(wt[n-1] > W) {
//     		return 0 + knapSack(W,wt,val,n-1);
//     	}
//     }
// };






// Using memoization

class Solution
{
    
    // TC : O(n * W)
    // SC : O(n * W) + O(n) auxiliary
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int t[1001][1001];
    
    int solve (int W, int wt[], int val[], int n) {
        
        // base case --> no items are left to rob or no space left in the bag to keep items
        
    	if(n == 0 || W == 0) {
    		return 0;
    	}
    	
    	// if function is already called for the particular value of n and W it's value won't be equal to -1, so we wont't call recursive function again, we will directly return 
    	if(t[n][W] != -1) {
    	    return t[n][W];
    	}


    	// if weight is less than or equal to W then we have two choices to pick it or not to pick it
    	if(wt[n-1] <= W) {
            return t[n][W] = max(val[n-1] + solve(W-wt[n-1],wt,val,n-1),0 + solve(W,wt,val,n-1));
    	}
    
    	// if weight is more than W no choice to pick it up, leave the item and move to next one
    	else if(wt[n-1] > W) {
    		return t[n][W] = 0 + solve(W,wt,val,n-1);
    	}
        
    }
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
       // make 2d matrix of the variables which are changing and initializing it with -1;
        memset(t,-1,sizeof(t)); 
       
        return solve(W,wt,val,n);

    }
};

