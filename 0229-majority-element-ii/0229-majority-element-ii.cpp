class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      unordered_map<int,int>mp;
      for(int a:nums) mp[a]++;
      int val=nums.size();
      val=val/3;

      vector<int>ans;
      for(auto it:mp)
      {
         if(it.second>val) ans.push_back(it.first);
      }
      return ans;

    }
};