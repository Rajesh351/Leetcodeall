class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[nums[i][j]]++;
            }
        }
        vector<int>v;
        for(auto a:mp)
        {
            if(a.second==nums.size()) v.push_back(a.first);
        }
         sort(v.begin(),v.end());
         return v;
    }
};