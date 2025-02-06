class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
      unordered_map<int,int>mp;
      int count=0;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i+1;j<nums.size();j++)
        {
            if(mp.find(nums[i]*nums[j])!=mp.end())
            {
                 int val=mp[nums[i]*nums[j]];
                 count+=8*val;
            }
            mp[nums[i]*nums[j]]++;
        }
      }  
      return count;
    }
};