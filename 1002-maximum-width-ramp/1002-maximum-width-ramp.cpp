class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    
    // Step 1: Create leftMin and rightMax arrays
    vector<int> leftMin(n), rightMax(n);
    
    // Fill leftMin
    leftMin[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        leftMin[i] = min(leftMin[i - 1], nums[i]);
    }
    
    // Fill rightMax
    rightMax[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], nums[i]);
    }
    
    // Step 2: Use two pointers to find the maximum width
    int i = 0, j = 0, ans = 0;
    
    while (i < n && j < n) {
        if (leftMin[i] <= rightMax[j]) {
            ans = max(ans, j - i);
            ++j;
        } else {
            ++i;
        }
    }
    
    return ans;
}

};