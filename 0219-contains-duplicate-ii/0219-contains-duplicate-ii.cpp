class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
       for(int i=0;i<nums.size();i++)
       {
          v.push_back({nums[i],i});
       }
       sort(v.begin(),v.end());

       for(int i=1;i<v.size();i++)
       {
          if(v[i-1].first==v[i].first && abs(v[i-1].second-v[i].second)<=k) return true;
       }
      return false;
    }
};