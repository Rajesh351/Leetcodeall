class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int pre = 0;
        int curr = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                curr++;
            else {
                if (pre < curr) {
                    pre = curr;
                    curr = 1;
                    ans = nums[i];
                }
            }
        }
        if (pre < curr) {
            pre = curr;
            curr = 1;
            ans = nums[nums.size()-1];
        }
        return ans;
    }
};