class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int ele=arr[queries[i][0]];
            for(int j=queries[i][0]+1;j<=queries[i][1];j++)
            {
               ele=ele^arr[j];
            }
            ans.push_back(ele);
        }
        return ans;
    }
};