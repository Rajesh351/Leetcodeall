class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int count = 0;
        int count1 = 0;
        int maj = 0;
        int maj1 = 0;
        int n=nums.size();
        for (int i = 0; i < nums.size(); i++) {

            if (maj == nums[i])
                count++;
            else if (maj1 == nums[i])
                count1++;
            else if (count == 0) {
                count = 1;
                maj = nums[i];
            } else if (count1 == 0) {
                count1 = 1;
                maj1 = nums[i];
            } else {
                count--;
                count1--;
            }
        }
        vector<int>v;
        int fre1=0;
        int fre2=0;
        for(int a:nums)
        {
            if(a==maj) fre1++;
            else if(a==maj1) fre2++;
        }
        if(fre1>floor(n/3)) v.push_back(maj);
        if(fre2>floor(n/3)) v.push_back(maj1);
        return v;
    }
};