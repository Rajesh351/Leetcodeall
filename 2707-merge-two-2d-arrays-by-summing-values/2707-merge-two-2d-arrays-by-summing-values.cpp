class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

       map<int,int>mp;
       for(int i=0;i<nums1.size();i++)
       {
          mp[nums1[i][0]]=nums1[i][1];
       } 
       for(int i=0;i<nums2.size();i++)
       {
         if(mp.find(nums2[i][0])!=mp.end())
         {
            int ele=mp[nums2[i][0]];
            mp[nums2[i][0]]=ele+nums2[i][1];
         }
         else
          mp[nums2[i][0]]=nums2[i][1];
       } 
       vector<vector<int>>ans;
       for(auto it:mp)
       {
         ans.push_back({it.first,it.second});
       }
       return ans;
    }
};