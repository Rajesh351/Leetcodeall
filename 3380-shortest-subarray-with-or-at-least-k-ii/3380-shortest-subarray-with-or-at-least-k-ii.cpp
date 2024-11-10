#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumSubarrayLength(std::vector<int>& nums, int k) {
        std::vector<int> count(32, 0);
        int start = 0, minLength = nums.size() + 1;

        for (int end = 0; end < nums.size(); ++end) {
            updateBits(count, nums[end], 1);

            while (start <= end && getVal(count) >= k) {
                minLength = std::min(minLength, end - start + 1);
                updateBits(count, nums[start], -1);
                ++start;
            }
        }
        return minLength == nums.size() + 1 ? -1 : minLength;
    }

private:
    void updateBits(std::vector<int>& count, int num, int val) {
        for (int i = 0; i < 32; ++i) {
            if (num & (1 << i)) {
                count[i] += val;
            }
        }
    }

    int getVal(const std::vector<int>& count) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (count[i] > 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};