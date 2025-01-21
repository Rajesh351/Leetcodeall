class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

       long long sum=accumulate(grid[0].begin(),grid[0].end(),0LL);
       long long a=0;
       long long ans=LONG_LONG_MAX;
       for(int i=0;i<grid[0].size();i++)
       {
           sum-=grid[0][i];
           long long best=max(sum,a);
           ans=min(ans,best);
           a+=grid[1][i];
       }
       return ans;
       
    }
};