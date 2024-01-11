class Solution {


    // TC : O(n * m) , n = coins length and m = amount
    // SC : O(n * m)

    
    int t[301][5001];
public:
    int change(int amount, vector<int>& coins) {


        int n = coins.size();

        // base case or initialization
        // if no of coins is 0, there are 0 ways to make amount
        // if amount is 0, we can make up the amount by taking empty array
        // if amount is 0 and no of coins is 0 it is possible to make up the amount

        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < amount + 1; j++) {
                if(i == 0) {
                    t[i][j] = 0;
                }
                if(j == 0) {
                    t[i][j] = 1;
                }
            }
        }

        // Unbounded knapsack

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < amount + 1; j++) {
                if(coins[i-1] <= j) {
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n][amount];
    }
};
