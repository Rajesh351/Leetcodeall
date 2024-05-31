class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int>v;
        for(auto s:mp)
        {
            if(s.second==1) v.push_back(s.first);
        }
        return v;
    }
};