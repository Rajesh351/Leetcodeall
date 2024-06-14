class Solution {
public:
    int minOperations(vector<int>& nums) {
        
       int ans=0;
       int last=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]<nums[i])
            {
                last=nums[i];
            }
            else
            {
                ++last;
                ans+=abs(last-nums[i]);
                nums[i]=last;
            }
        }
        return ans;
    }
};