// Author: Juyoung Moon
// https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int height = grid.size();
        int width = grid[0].size();

        // intialize first col
        for (int r = 1; r < height; r++) {
            grid[r][0] = grid[r-1][0] + grid[r][0];
        }
        // intialize first row
        for (int c = 1; c < width; c++) {
            grid[0][c] = grid[0][c-1] + grid[0][c];
        }

        for (int r = 1; r < height; r++) {
            for (int c = 1; c < width; c++) {
                int topCost = grid[r-1][c];
                int leftCost = grid[r][c-1];
                grid[r][c] += min(topCost, leftCost);
            }
        }

        return grid[height-1][width-1];
    }
};