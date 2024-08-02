class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int p=0,q=grid[0].size()-1;
        
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(i==j||(i==p&&j==q)){
                    //diagonal elements
                    if(grid[i][j]==0)
                        return false;
                }
                else{
                    //non diagonal elements
                    if(grid[i][j]!=0)
                        return false;
                }
            }
            p++;
            q--;
        }
        
        return true;
    }
};