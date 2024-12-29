class Solution {
public:
    int  MOD= 1e9 + 7;
    int numWays(vector<string>& words, string target) {
          int m = target.size();
    int n = words[0].size();
    
    // Frequency array: freq[c][j] gives the count of character `c` at index `j` across all strings in `words`
    vector<vector<int>> freq(26, vector<int>(n, 0));
    for (const string& word : words) {
        for (int j = 0; j < n; ++j) {
            freq[word[j] - 'a'][j]++;
        }
    }

    // DP array: dp[i][j] represents ways to form the first `i` characters of `target` using the first `j` characters of `words`
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    
    // Base case: There's one way to form an empty target
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Inherit the ways from the previous column
            dp[i][j] = dp[i][j - 1];
            
            // Add ways if the character matches
            char targetChar = target[i - 1];
            if (freq[targetChar - 'a'][j - 1] > 0) {
                dp[i][j] += dp[i - 1][j - 1] * freq[targetChar - 'a'][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    // The result is the number of ways to form the full target using all columns
    return dp[m][n];
    }
};