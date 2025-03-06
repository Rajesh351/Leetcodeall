class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        
       int n =grid.size();
    
       int  sum=n*n;
       vector<int>ans;
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
            for(int j=0;j<n;j++)
            {
                if(mp.find(grid[i][j])!=mp.end())
                {
                     ans.push_back(grid[i][j]);
                }
                else mp[grid[i][j]]++;
            }
       }
       for(int i=1;i<=sum;i++)
       {
          if(mp.find(i)==mp.end())
          {
             ans.push_back(i);
             return ans;
          }
       }
       return ans;
        
    }
};