class Solution {
public:
    bool canDistribute(vector<int>& nums, int maxBalls, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            operations += (balls - 1) / maxBalls; // Calculate required splits
            if (operations > maxOperations) return false; // Too many operations needed
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1; // Minimum possible size of a bag
        int high = *max_element(nums.begin(), nums.end()); // Maximum possible size
        int result = high;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Current maximum size to test
            if (canDistribute(nums, mid, maxOperations)) {
                result = mid; // If valid, try smaller sizes
                high = mid - 1;
            } else {
                low = mid + 1; // If not valid, try larger sizes
            }
        }
        return result; // Minimum size found
    }
};