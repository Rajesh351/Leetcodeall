class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>>ans;
       
       if(num==0) return ans;
       ans.push_back({1});
       for(int i=1;i<num;i++)
       {
            vector<int>temp;
            temp.push_back(1);
            int j=1;
            while(j<i)
            {
                 temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
                 j++;
            }
            temp.push_back(1);
            ans.push_back(temp);
       }
       return ans;
        
    }
};