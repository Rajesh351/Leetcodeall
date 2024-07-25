class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n + m - 1); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index = i + j;
            ans[index].push_back(mat[i][j]);
        }
    }
        vector<int>ans1;
        bool check=true;
        for(int i=0;i<ans.size();i++)
        {
           if(check)
           {
             for(int j=ans[i].size()-1;j>=0;j--)
            {
                ans1.push_back(ans[i][j]);
            }
            check=false;
           }
           else
           {
             for(int j=0;j<ans[i].size();j++)
            {
                ans1.push_back(ans[i][j]);
            }
            check=true;
           }
           
        }
        return ans1;
    }
};