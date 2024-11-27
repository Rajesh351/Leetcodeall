class Solution {
public:
vector<vector<int>>ans;
   void slove(int idx,vector<int>& nums)
   {
      if(idx==nums.size()-1)
      {
        ans.push_back(nums);
        return;
      }
      for(int i=idx;i<nums.size();i++)
      {
        swap(nums[idx],nums[i]);
        slove(idx+1,nums);
        swap(nums[idx],nums[i]);
      }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        slove(0,nums);
        return ans;
    }
};