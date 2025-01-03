class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {


        vector<long long>a,b;
        a.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
             a.push_back(a[i-1]+nums[i]);
        }
        int count=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>=0 && nums[i]<nums.size()-1) count=nums[i];
            b.push_back(count);
        }
        long long last=a[a.size()-1];
        int idx=0;
        for(int i=0;i<a.size()-1;i++)
        {
            long long rem=last-a[i];
            if(a[i]<rem) continue;
            if(a[i]>=rem || b[i+1]>0) idx++;
        }
        return idx;
        
    }
};