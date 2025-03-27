class Solution {
public:
    int majorityElement(vector<int>& nums) {
          unordered_map<int,int>mp;
         int ans=-1;
         for(int a:nums) mp[a]++;
         int v=0;
         for(auto it:mp)
         {
            if(ans<it.second)
            {
                ans=it.second;
                v=it.first;
            }
         } 
         return v;

    }
};