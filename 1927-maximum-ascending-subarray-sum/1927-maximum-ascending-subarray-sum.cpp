class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int maxans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = nums[i];
            int val = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (val < nums[j]) {
                    sum += nums[j];
                    val = nums[j];
                } else
                    break;
            }
            maxans = max(maxans, sum);
        }
        return maxans;
    }
};