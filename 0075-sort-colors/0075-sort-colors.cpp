class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int one=0,zero=0,two=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) zero++;
            if(nums[i]==1) one++;
            if(nums[i]==2) two++;
        }
        for(int i=0;i<zero;i++)
        {
            nums[i]=0;
        }
        for(int i=zero;i<one+zero;i++)  nums[i]=1;
        for(int j=one+zero;j<one+zero+two;j++) nums[j]=2;
    }
};