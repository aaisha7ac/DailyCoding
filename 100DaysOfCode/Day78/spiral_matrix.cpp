class Solution {

    // TC : O(m * n)
    // SC : O(1)

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        
        int sr = 0;
        int sc = 0;

        vector<int>ans;

        while(sr < row && sc < col) {

            for(int i = sc; i < col; i++) {
                ans.push_back(matrix[sr][i]);
            }
            sr++;

            for(int i = sr; i < row; i++) {
                ans.push_back(matrix[i][col-1]);
            }
            col--;

            if(sr < row) {

                for(int i = col - 1; i >= sc; i--) {
                    ans.push_back(matrix[row-1][i]);
                }

                row--;
            }

            if(sc < col) {
                for(int i = row - 1; i >= sr; i--) {
                    ans.push_back(matrix[i][sc]);
                }
                sc++;

            }

        }

        return ans;
        
    }
};