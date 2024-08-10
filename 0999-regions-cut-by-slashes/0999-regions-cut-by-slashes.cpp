class Solution {
public:

    void bfs(vector<vector<int>>&mat,int i,int j){
    if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]==1) return;
        mat[i][j]=1;

        bfs(mat,i+1,j);
        bfs(mat,i,j+1);
        bfs(mat,i-1,j);
        bfs(mat,i,j-1);
    }
    int regionsBySlashes(vector<string>& grid) {
        
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>mat(row*3,vector<int>(col*3,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='/')
                {
                  mat[i*3][j*3+2]=1;
                   mat[i*3+1][j*3+1]=1;
                    mat[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\')
                {
                     mat[i*3][j*3]=1;
                      mat[i*3+1][j*3+1]=1;
                       mat[i*3+2][j*3+2]=1;
                }
            }
        }
         int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    bfs(mat,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};