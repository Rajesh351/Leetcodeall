class Solution {
public:
    bool ismagic(vector<vector<int>>& grid,int row,int col)
    {
         vector<int> count(10, 0);
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];
        
        // Check rows
        for (int i = row; i < row + 3; i++) {
            int rowSum = 0;
            for (int j = col; j < col + 3; j++) {
                rowSum += grid[i][j];
                if (grid[i][j] < 1 || grid[i][j] > 9 || ++count[grid[i][j]] > 1)
                    return false;
            }
            if (rowSum != sum) return false;
        }

        // Check columns
        for (int j = col; j < col + 3; j++) {
            int colSum = 0;
            for (int i = row; i < row + 3; i++) {
                colSum += grid[i][j];
            }
            if (colSum != sum) return false;
        }

        // Check diagonals
        int diag1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int diag2 = grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col];
        
        if (diag1 != sum || diag2 != sum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {

      int n=grid.size();
      int m=grid[0].size();
      int count=0;
      for(int i=0;i<=n-3;i++)
      {
        for(int j=0;j<=m-3;j++)
        {
            if(grid[i+1][j+1]==5 && ismagic(grid,i,j)) count++;
        }
      }
      return count;
    }
};