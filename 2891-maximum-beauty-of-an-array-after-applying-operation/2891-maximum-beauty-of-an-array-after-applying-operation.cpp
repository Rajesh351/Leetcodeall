class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
      sort(nums.begin(), nums.end());

    int maxBeauty = 0;  // Result variable
    int start = 0;      // Sliding window start index

    // Iterate over the sorted array
    for (int end = 0; end < nums.size(); end++) {
        // Maintain the range such that nums[end] - nums[start] <= 2 * k
        while (nums[end] - nums[start] > 2 * k) {
            start++;
        }
        // Update the maximum beauty as the current window size
        maxBeauty = max(maxBeauty, end - start + 1);
    }

    return maxBeauty;
    }
};