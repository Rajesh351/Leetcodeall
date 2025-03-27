class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candi=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(candi==nums[i])
             count++;
            
            else
            {
                if(count==0)
                {
                    candi=nums[i];
                    count=1;
                }

                else  count--;
            }
        }
        return candi;
        
    }
};