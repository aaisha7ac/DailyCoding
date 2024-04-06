class Solution {
    
    // TC : O(n^3)
    // SC : O(n * m)

public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        queue<pair<int,int>>q;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }     


        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = c - 1; k >= 0; k--) {
                matrix[r][k] = 0;
            }

            for(int k = c + 1; k < col; k++) {
                matrix[r][k] = 0;
            }

            for(int k = r - 1; k >= 0; k--) {
                matrix[k][c] = 0;
            }

            for(int k = r + 1; k < row; k++) {
                matrix[k][c] = 0;
            }

        }

    }
};


class Solution {
    
    // TC : O(2 * n *m)
    // SC : O(n + m)

public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>row(n,0),col(m,0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }




       

    }
};


class Solution {
    
    // TC : O(n * m)
    // SC : O(1)

public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        // int col[m] = {0}; -->matrix[0][...]
        // int row[n] = {0}; -->matrix[...][0]

        int col0 = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) {

                    // mark the ith row
                    matrix[i][0] = 0;

                    // mark the jth col
                    if(j != 0) {
                        matrix[0][j] = 0;
                    }
                    else {
                        col0 = 0;
                    }
                }
            }
        }

        // Not considering the 0th row and col
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                if(matrix[i][j] != 0) {

                    // check for row and col

                    if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                        matrix[i][j] = 0;
                    }
                }

            }
        }

        // For 0th row and col

        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }


    }
};

