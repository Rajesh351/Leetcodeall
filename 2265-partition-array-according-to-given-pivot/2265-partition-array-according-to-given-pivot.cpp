class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     vector<int>le;
     int count=0;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i]<pivot) le.push_back(nums[i]);
        if(pivot==nums[i]) count++;
     }
     for(int i=0;i<count;i++) le.push_back(pivot);

     for(int i=0;i<nums.size();i++)
     {
        if(nums[i]>pivot) le.push_back(nums[i]);
     }
     return le;
        
    }
};