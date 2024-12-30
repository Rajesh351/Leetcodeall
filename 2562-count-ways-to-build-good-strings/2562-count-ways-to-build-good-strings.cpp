class Solution {
public:
    const int MOD = 1e9 + 7;
    unordered_map<int, int> dp; // Memoization table with modulo

    int solve(int num, int low, int high, int z, int o) {
        // Base case: If num exceeds the high range
        if (num > high)
            return 0;

        // Check memo table
        if (dp.find(num) != dp.end())
            return dp[num];

        // Count the current number if it's within the range
        int current_count = (num >= low && num <= high) ? 1 : 0;

        // Recursive calls with modulo
        current_count = (current_count + solve(num + z, low, high, z, o)) % MOD;
        current_count = (current_count + solve(num + o, low, high, z, o)) % MOD;

        // Store the result in the memo table with modulo
        dp[num] = current_count;

        return current_count;
    }
    int countGoodStrings(int low, int high, int zero, int one) {

        int num = 0;
        // solve(num,low,high,zero,one);
        return solve(num, low, high, zero, one);
    }
};