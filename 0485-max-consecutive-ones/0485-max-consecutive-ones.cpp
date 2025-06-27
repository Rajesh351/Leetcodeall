class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone=0;
        int count=0;
        for(int a:nums)
        {
             if(a==1) count++;
             else 
             {
                maxone=max(maxone,count);
                count=0;
             }
        }
        maxone=max(maxone,count);
        return maxone;
    }
};