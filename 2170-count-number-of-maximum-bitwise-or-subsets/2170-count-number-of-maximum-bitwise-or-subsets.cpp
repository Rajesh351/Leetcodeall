class Solution {
public:
int count=0;
    void printSubsets(vector<int>& nums, vector<int>& subset, int index,int ans) {
    if (index == nums.size()) {
      int result = 0; 

    for (int num : subset) {
        result |= num; 
    }
    if(result==ans) count++;
        return;
    }

    subset.push_back(nums[index]);
    printSubsets(nums, subset, index + 1,ans);

    
    subset.pop_back();
    printSubsets(nums, subset, index + 1,ans);
}
    int countMaxOrSubsets(vector<int>& nums) {
        
        int result = 0; 

    for (int num : nums) {
        result |= num; 
    }
    vector<int> subset;
     printSubsets(nums, subset,0,result);
     return count;
    }
};