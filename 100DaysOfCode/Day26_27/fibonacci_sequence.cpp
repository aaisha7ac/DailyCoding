class Solution {

    // Using recursion
    // TC : O(2^n)
    // SC : O(n) , stack space
    
public:
    int fib(int n) {
        
        if(n <= 1) {
            return n;
        }

        return fib(n-1) + fib(n-2);
    }
};

class Solution {

    // Memoization
    // TC : O(n)
    // SC : O(n) + O(n) , stack and dp vector
    
public:
    int fibonacci(vector<int> &dp,int n) {

        if(n <= 1) {
            return n;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = fibonacci(dp,n-1) + fibonacci(dp,n-2);
    }
    int fib(int n) {
        
        vector<int>dp(n+1,-1);

        return fibonacci(dp,n);
    }
};


class Solution {

    // Tabulation
    // TC : O(n)
    // SC : O(n) , for dp array
public:
    int fib(int n) {

        if(n <= 1) {
            return n;
        }
        
        int dp[n+1];

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];


    }
};

class Solution {

    // Space optimisation
    // TC : O(n)
    // SC : O(1)

public:
    int fib(int n) {

        if(n <= 1) {
            return n;
        }
        
        int prev = 0;
        int prev_2 = 1;
        int curr = 0;

        for(int i = 0; i < n; i++) {
           prev = prev_2;
           prev_2 = curr;
           curr = prev + prev_2;
        }

        return curr;
        
    }
};