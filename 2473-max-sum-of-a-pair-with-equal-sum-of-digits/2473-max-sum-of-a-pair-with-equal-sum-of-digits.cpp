class Solution {
public:
    int maximumSum(vector<int>& nums) {

       vector<int>digitsum;
       for(int i=0;i<nums.size();i++)
       {
            int curr=nums[i];
            int sum=0;
            while(curr>0)
            {
              sum+=curr%10;
              curr=curr/10;
            }
            digitsum.push_back(sum);
       }
       int ans=INT_MIN;
       unordered_map<int,int>mp;
       mp[digitsum[0]]=nums[0];
       for(int i=1;i<nums.size();i++)
       {
          if(mp.find(digitsum[i])!=mp.end())
          {
            int curr=mp[digitsum[i]];
            ans=max(ans,curr+nums[i]);
            if(curr<nums[i]) mp[digitsum[i]]=nums[i];

          }
          else
          mp[digitsum[i]]=nums[i];
       } 
       return ans==INT_MIN?-1:ans;
    }
};