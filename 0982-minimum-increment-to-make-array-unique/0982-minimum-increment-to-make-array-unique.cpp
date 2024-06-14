class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        

        unordered_map<int,int>mp;
        int count=0,last=-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(mp.count(nums[i]))
            {
              ++last;
              count+=abs(last-nums[i]);
              mp[last]++;
            }
            else
            {
                mp[nums[i]]++;
                last=nums[i];
            }
        }
        return count;
    }
};