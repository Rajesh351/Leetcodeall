class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxele=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            int temp=-1;
             for(int j=i+1;j<nums.size();j++)
             {
                if(nums[i]<nums[j])
                temp=max(temp,nums[j]-nums[i]);
             }
              maxele=max(maxele,temp);
        }
        return maxele;
    }
};