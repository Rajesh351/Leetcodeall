class Solution {
public:
   int slove(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& memo) {
        // Base condition: Out of bounds or reached the last column
        if (i < 0 || i >= grid.size() || j >= grid[0].size()) {
            return 0;
        }
        if (j == grid[0].size() - 1) {
            return 0;  // No more moves from the last column
        }
        
        // Check memoized results
        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int upRight = 0, right = 0, downRight = 0;

        // Move to (row - 1, col + 1) if within bounds and satisfies condition
        if (i - 1 >= 0 && j + 1 < grid[0].size() && grid[i][j] < grid[i - 1][j + 1]) {
            upRight = 1 + slove(grid, i - 1, j + 1, memo);
        }

        // Move to (row, col + 1) if within bounds and satisfies condition
        if (j + 1 < grid[0].size() && grid[i][j] < grid[i][j + 1]) {
            right = 1 + slove(grid, i, j + 1, memo);
        }

        // Move to (row + 1, col + 1) if within bounds and satisfies condition
        if (i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i][j] < grid[i + 1][j + 1]) {
            downRight = 1 + slove(grid, i + 1, j + 1, memo);
        }

        // Memoize the maximum moves from this cell
        memo[i][j] = max({upRight, right, downRight});
        return memo[i][j];
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        int ansval = 0;
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));

        // Start from each row in the first column
        for (int i = 0; i < grid.size(); i++) {
            ansval = max(ansval, slove(grid, i, 0, memo));
        }
        
        return ansval;
    }
};