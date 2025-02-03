class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
      int n = nums.size();
    if (n <= 1) {
        return n;
    }
          int longestInc = 1;
    int longestDec = 1;
    int currInc = 1;
    int currDec = 1;

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            currInc++;
            currDec = 1;
        } else if (nums[i] < nums[i - 1]) {
            currDec++;
            currInc = 1;
        } else {
            currInc = 1;
            currDec = 1;
        }

        longestInc = max(longestInc, currInc);
        longestDec = max(longestDec, currDec);
    }

    return max(longestInc, longestDec);
    }
};