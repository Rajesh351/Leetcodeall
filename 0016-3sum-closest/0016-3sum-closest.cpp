class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
          std::sort(nums.begin(), nums.end());
        int closest_sum = std::numeric_limits<int>::max();
        int smallest_diff = std::numeric_limits<int>::max();

        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t left = i + 1;
            size_t right = nums.size() - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                int current_diff = std::abs(target - current_sum);

                if (current_diff < smallest_diff) {
                    closest_sum = current_sum;
                    smallest_diff = current_diff;
                }

                if (current_sum < target) {
                    ++left;
                } else if (current_sum > target) {
                    --right;
                } else {
                    return current_sum;
                }
            }
        }

        return closest_sum;
    }
};