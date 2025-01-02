class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
     sort(nums.begin(),nums.end());
     int i=0;
     int ans=0;
     while(i<nums.size())
     {
        ans+=min(nums[i],nums[i+1]);
        i=i+2;
     }  
     return ans;
    }
};