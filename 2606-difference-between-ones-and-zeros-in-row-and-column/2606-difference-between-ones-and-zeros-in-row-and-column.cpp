class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
         vector<vector<int>>ans;
        vector<int>rowone(grid.size(),0);
        vector<int>colone(grid[0].size(),0);
         vector<int>rowzero(grid.size(),0);
        vector<int>colzero(grid[0].size(),0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                 if(grid[i][j]==1)
                 {
                    rowone[i]++;
                    colone[j]++;
                 }
                 else if(grid[i][j]==0)
                 {
                    rowzero[i]++;
                    colzero[j]++;
                 }
            }
            
        } 
        for(int i=0;i<grid.size();i++)
        {
            vector<int>ans1;
            for(int j=0;j<grid[0].size();j++)
            {
              ans1.push_back(rowone[i]+colone[j]-rowzero[i]-colzero[j]);
            }
            ans.push_back(ans1);
        }
        return ans;

    }
};