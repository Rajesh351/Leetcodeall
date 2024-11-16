class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
     vector<int> result;
    int n = nums.size();

    for (int i = 0; i <= n - k; i++) {
        bool isConsecutiveAscending = true;

        // Check if the current window is consecutive and ascending
        for (int j = i; j < i + k - 1; j++) {
            if (nums[j + 1] - nums[j] != 1) { // Difference must be exactly 1
                isConsecutiveAscending = false;
                break;
            }
        }

        if (!isConsecutiveAscending) {
            result.push_back(-1); // Add -1 if the window is not consecutive and ascending
        } else {
            // Compute the maximum if the window is consecutive and ascending
            int maxElement = nums[i + k - 1]; // Last element in sorted window is the max
            result.push_back(maxElement);
        }
    }

    return result;
    }
};