class Solution {
    void dfs(vector<vector<int>>&grid,int row,int col){
        int n=grid.size();
        int m=grid[0].size();
        if(row<0 or col<0 or row>=n or col>=m or grid[row][col]==0)return;
        grid[row][col]=0;

        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            dfs(grid,nrow,ncol);
        }
    }
    int number_of_islands(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 or m==0)return 0;
        vector<vector<int>>grid_copy=grid;
        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid_copy[i][j]==1){
                    dfs(grid_copy,i,j);
                    curr++;
                }
            }
        }
        return curr;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 or m==0)return 0;
        int curr=number_of_islands(grid);
        if(curr!=1){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(number_of_islands(grid)!=1){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        return 2;
    }
};