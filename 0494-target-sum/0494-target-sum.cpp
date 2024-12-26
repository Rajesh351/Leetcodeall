class Solution {
public:
 void slove(int index, int sum, int target, vector<int>& arr, int& count) {
    // Base case: All elements are processed
    if (index >= arr.size()) {
        if (sum == target) count++; // Increment count if target is achieved
        return;
    }

    // Add current element
    slove(index + 1, sum + arr[index], target, arr, count);

    // Subtract current element
    slove(index + 1, sum - arr[index], target, arr, count);
}

int findTargetSumWays(vector<int>& nums, int target) {
    int count = 0; // Initialize count
    slove(0, 0, target, nums, count); // Start recursive function
    return count; // Return the number of ways
}


};