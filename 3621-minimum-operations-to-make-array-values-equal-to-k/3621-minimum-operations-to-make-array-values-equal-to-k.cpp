class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        if(nums.size()==1)
        {
            if(nums[0]==k) return 0;
            if(nums[0]<k)  return -1;
            return 1;
        }
        unordered_map<int,int>mp;
        for(int a:nums) 
        {
            mp[a]++;
            if(a<k) return -1;
        }

        int count=0;
        for(auto it:mp)
        {
            if(it.first>k) count++;
        }
        //if(count<k) return -1;
        return count;
    }
};