class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

       int i=nums1.size()-1;
       int j=nums2.size()-1;
       vector<vector<int>>ans;
       while(i>=0 && j>=0)
       {
          if(nums1[i][0]==nums2[j][0])
          {
            ans.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
            i--;
            j--;
          }
          else if(nums1[i][0]>nums2[j][0])
          {
              ans.push_back({nums1[i][0],nums1[i][1]});
              i--;
          }
          else
          {
             ans.push_back({nums2[j][0],nums2[j][1]});
              j--;
          }
       }
      while(i>=0)
      {
        ans.push_back({nums1[i][0],nums1[i][1]});
              i--;
      }
      while(j>=0)
      {
         ans.push_back({nums2[j][0],nums2[j][1]});
              j--;
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};