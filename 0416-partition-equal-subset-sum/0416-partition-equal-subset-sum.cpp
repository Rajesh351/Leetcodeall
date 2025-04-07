class Solution {
public:
    bool solve(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(sum == 0) return true;
        if(idx >= arr.size() || sum < 0) return false;

        if(dp[idx][sum] != -1) return dp[idx][sum];

        bool take = solve(idx + 1, sum - arr[idx], arr, dp);
        bool notake = solve(idx + 1, sum, arr, dp);

        return dp[idx][sum] = take || notake;
    }

    bool canPartition(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total % 2 != 0) return false;

        int sum = total / 2;
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return solve(0, sum, arr, dp);
    }
};
