#include <vector>
// #include <unordered_set>

using namespace std;

// TC : O(row * col)
// SC : O(row * col)

class Solution {

    private:
    void dfs(vector<vector<int>>& heights, int r, int c, int prevHeight, vector<vector<bool>>& visited) {
        if (r < 0 || r >= heights.size() || c < 0 || c >= heights[0].size() || visited[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        // for all direction
        visited[r][c] = true;
        dfs(heights, r + 1, c, heights[r][c], visited);
        dfs(heights, r - 1, c, heights[r][c], visited);
        dfs(heights, r, c + 1, heights[r][c], visited);
        dfs(heights, r, c - 1, heights[r][c], visited);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<int>> res;
        
        if (ROWS == 0 || COLS == 0) return res;

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // for first and last column
        for (int r = 0; r < ROWS; ++r) {
            dfs(heights, r, 0, INT_MIN, pac);
            dfs(heights, r, COLS - 1, INT_MIN, atl);
        }


        // for first and last row
        for (int c = 0; c < COLS; ++c) {
            dfs(heights, 0, c, INT_MIN, pac);
            dfs(heights, ROWS - 1, c, INT_MIN, atl);
        }

        // Check for cells connected to both oceans
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};