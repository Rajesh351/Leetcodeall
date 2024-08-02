class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int onecount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                onecount++;
        }

        int n = nums.size();
        vector<int> v(n + onecount);
        for (int i = 0; i < n; i++) {
            v[i] = nums[i];
        }
        for (int i = 0; i < onecount; i++) {
            v[n + i] = nums[i];
        }
        int count = 0;
        for (int i = 0; i < onecount; i++) {
            if (v[i] == 0)
                count++;
        }

        int ans = count;
        for (int i = 1; i <= n; i++) {
            if (v[i - 1] == 0)
                count--; 
            if (v[i + onecount - 1] == 0)
                count++; 
            ans = min(ans, count);
        }

        return ans;
    }
};