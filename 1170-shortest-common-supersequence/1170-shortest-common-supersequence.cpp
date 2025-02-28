
class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
        int m = X.length(), n = Y.length();
    
        // DP table to store LCS length
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Filling DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];  // Match found
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Take max of left or top
            }
        }

        // Backtracking to construct SCS
        int i = m, j = n;
        string scs = "";

        while (i > 0 && j > 0) {
            if (X[i - 1] == Y[j - 1]) { 
                // If characters match, add to result
                scs = X[i - 1] + scs;
                i--; j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) { 
                // Move in the direction of the larger value
                scs = X[i - 1] + scs;
                i--;
            } else {
                scs = Y[j - 1] + scs;
                j--;
            }
        }

        // Add remaining characters from X and Y
        while (i > 0) {
            scs = X[i - 1] + scs;
            i--;
        }
        while (j > 0) {
            scs = Y[j - 1] + scs;
            j--;
        }

        return scs;
    }
};

