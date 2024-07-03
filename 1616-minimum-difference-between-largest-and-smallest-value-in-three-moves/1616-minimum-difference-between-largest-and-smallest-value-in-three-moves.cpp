class Solution {
public:
    int minDifference(vector<int>& nums) {
        

          std::sort(nums.begin(), nums.end());
    int n = nums.size();
    
    if (n <= 3) {
        return 0;
    }
    
    return std::min({nums[n - 4] - nums[0], nums[n - 3] - nums[1], nums[n - 2] - nums[2], nums[n - 1] - nums[3]});
    }
};