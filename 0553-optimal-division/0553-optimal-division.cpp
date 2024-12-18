class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        

        if(nums.size()==1) return to_string(nums[0]);
        else if(nums.size()==2)
         return to_string(nums[0])+"/"+to_string(nums[1]);
         else
         {
             string str="";
             str+=to_string(nums[0])+"/(";
             for(int i=1;i<nums.size()-1;i++)
             {
                str+=to_string(nums[i])+"/";
             }
             str+=to_string(nums.back());
             str+=")";
             return str;
         }
         return "";
    }
};