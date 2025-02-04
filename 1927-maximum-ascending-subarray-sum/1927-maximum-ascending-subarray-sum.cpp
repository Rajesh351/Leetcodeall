class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
       int sum=nums[0];
       int maxans=0;
       for(int i=1;i<nums.size();i++)
       {
          if(nums[i-1]<nums[i])
          {
            sum+=nums[i];
          }
          else
          {
              
             maxans=max(maxans,sum);
             sum=nums[i];
          }
       }
       return maxans=max(maxans,sum);
    }
};