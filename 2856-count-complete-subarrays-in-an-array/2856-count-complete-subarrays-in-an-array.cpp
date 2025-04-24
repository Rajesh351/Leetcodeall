class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int a:nums) mp[a]++;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,int>mp1;
            for(int j=i;j<nums.size();j++)
            {
                mp1[nums[j]]++;
               if(mp.size()==mp1.size()) count++;

            }
        }
        return count;
    }
};