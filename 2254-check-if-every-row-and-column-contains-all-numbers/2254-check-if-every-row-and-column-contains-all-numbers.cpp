class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
           unordered_map<int,int>mp,mp1;
            for(int j=0;j<m;j++)
            {
              if(mp.find(matrix[i][j])==mp.end()) mp[matrix[i][j]]++;
              else return false;
             if(mp1.find(matrix[j][i])==mp.end()) mp1[matrix[j][i]]++;
              else return false;
            }
        }
        return true;
    }
};