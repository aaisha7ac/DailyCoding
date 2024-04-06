class Solution {

    // TC : O(n^2)
    // SC : O(n^2)

public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<vector<int>>ans(n,vector<int>(n,0));

        for(int i = 0; i < n; i++) {
            int k = 0;
            for(int j = n - 1; j >= 0; j--) {
                ans[i][k] = matrix[j][i];
                k++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = ans[i][j];
            }
        }
        
    }
};


class Solution {

    // TC : O(n^2)
    // SC : O(1)

public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // 1. Transpose of matrix (converting col into row)
        // This loop will run only for upper half of diagonal

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // 2. Reverse the row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};


