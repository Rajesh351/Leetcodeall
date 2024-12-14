class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
      int n=nums.size();
      int i=0;
      int j=0;
      map<int,int>mp;
      long long ans=0;
      while(i<n)
      {
         mp[nums[i]]++;
         while(abs(mp.rbegin()->first - mp.begin()->first)>2)
         {
            mp[nums[j]]-=1;
            if(mp[nums[j]]==0) mp.erase(nums[j]);
            j++;
         }
         ans+=i-j+1;
         i++;
      }
      return ans;
    }
};