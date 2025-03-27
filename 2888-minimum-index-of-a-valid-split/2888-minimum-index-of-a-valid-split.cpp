class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;

        // Step 1: Find the dominant element
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Find element with maximum frequency
        int dominant = -1, maxFreq = 0;
        for (auto& [num, count] : freq) {
            if (count > maxFreq) {
                maxFreq = count;
                dominant = num;
            }
        }

        // If dominant element does not occur more than n/2 times, return -1
        if (maxFreq * 2 <= n) return -1;

        // Step 2: Use prefix count to find the minimum index
        int leftCount = 0, totalCount = maxFreq;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) leftCount++;

            // Left partition should have more than half
            if (leftCount * 2 > (i + 1)) {
                int rightCount = totalCount - leftCount;
                int rightSize = n - (i + 1);

                // Right partition should also have more than half
                if (rightCount * 2 > rightSize) {
                    return i;
                }
            }
        }
        return -1;
    }
};
