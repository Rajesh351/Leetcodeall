class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

    int ans = 0;  
    int val = 0;  // Bitmask to track active bits
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
        while ((val & nums[right]) != 0) {
            val ^= nums[left];  // Remove left element from bitmask
            left++;
        }

        val |= nums[right];  // Add current element to bitmask
        ans = max(ans, right - left + 1);
    }
    return ans;
    }
};