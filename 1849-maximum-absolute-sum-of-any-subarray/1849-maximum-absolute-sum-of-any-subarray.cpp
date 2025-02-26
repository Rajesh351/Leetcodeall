class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int max1 = abs(nums[0]);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            max1 = max(max1, abs(sum));
            if (sum < 0)
                sum = 0;
        }
        int min_sum = INT_MAX, current_min = 0;

        for (int num : nums) {
            current_min = min(num, current_min + num);
            min_sum = min(min_sum, current_min);
        }

       return max( max1,abs(min_sum));
    }
};