class Solution {

    // TC : O(row * col)
    // SC : O(col)
    
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < row; i++) {
            vector<int>temp;
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == -1) {
                    int max = -1;
                    
                    for(int k = 0; k < row; k++) {
                        if(matrix[k][j] >= max) {
                            max = matrix[k][j];
                        }
                    }
                    
                    temp.push_back(max);
                }
                else {
                    temp.push_back(matrix[i][j]);
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
    
};