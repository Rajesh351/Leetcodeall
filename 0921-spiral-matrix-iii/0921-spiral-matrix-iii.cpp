class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>dir={
            {0,1},//EASR
            {1,0} ,//south
            {0,-1},//west
            {-1,0}//north
        };
        int step=0;
        int dirs=0;
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        while(ans.size()<rows*cols)
        {
            if(dirs==0 || dirs==2) step++;
            for(int i=0;i<step;i++)
            {
                rStart+=dir[dirs][0];
                cStart+=dir[dirs][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)  ans.push_back({rStart,cStart});

            }
            dirs=(dirs+1)%4;
        }
       return ans;
    }
};