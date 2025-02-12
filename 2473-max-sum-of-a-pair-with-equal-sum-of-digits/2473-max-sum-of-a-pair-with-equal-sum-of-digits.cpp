class Solution {
public:
    int a(int curr)
    {
            int sum=0;
            while(curr>0)
            {
              sum+=curr%10;
              curr=curr/10;
            }
            return sum;
    }
    int maximumSum(vector<int>& nums) {

      
       int ans=INT_MIN;
       int digitsum=a(nums[0]);
       unordered_map<int,int>mp;
       mp[digitsum]=nums[0];
       for(int i=1;i<nums.size();i++)
       {
            digitsum=a(nums[i]);
          if(mp.find(digitsum)!=mp.end())
          {
            int curr=mp[digitsum];
            ans=max(ans,curr+nums[i]);
            if(curr<nums[i]) mp[digitsum]=nums[i];

          }
          else
          mp[digitsum]=nums[i];
       } 
       return ans==INT_MIN?-1:ans;
    }
};