class Solution {
public:
   long long solve(int idx, vector<vector<int>>& questions, vector<long long>& dp) {
    if (idx >= questions.size()) return 0; // Base case

    if (dp[idx] != -1) return dp[idx]; // पहले से कैलकुलेटेड वैल्यू

    // दो ऑप्शन: इस प्रश्न को लें या छोड़ दें
    int next = idx + questions[idx][1] + 1;
    long long take = questions[idx][0] + solve(next, questions, dp);
    long long skip = solve(idx + 1, questions, dp);

    return dp[idx] = max(take, skip); // मैक्स वैल्यू स्टोर करें
}


    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(100001, -1);
        return solve(0 ,questions, dp);
    }
};