class Solution {
public:

long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    vector<long long> dp(n, 0), left(n, 0), right(n, 0);
    
    // Initialize dp with the first row
    for (int j = 0; j < n; ++j) {
        dp[j] = points[0][j];
    }

    // Iterate over each row starting from the second
    for (int i = 1; i < m; ++i) {
        // Calculate left max
        left[0] = dp[0];
        for (int j = 1; j < n; ++j) {
            left[j] = max(left[j-1] - 1, dp[j]);
        }

        // Calculate right max
        right[n-1] = dp[n-1];
        for (int j = n-2; j >= 0; --j) {
            right[j] = max(right[j+1] - 1, dp[j]);
        }

        // Update dp for the current row
        for (int j = 0; j < n; ++j) {
            dp[j] = points[i][j] + max(left[j], right[j]);
        }
    }

    // Return the maximum points we can get in the last row
    return *max_element(dp.begin(), dp.end());
}

};