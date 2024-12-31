class Solution {
public:

   int slove(int i, const vector<int>& days, const vector<int>& costs, vector<int>& dp)
{
    if (i >= days.size())
        return 0;

    if (dp[i] != -1) // Check if already computed
        return dp[i];

    // Cost for a 1-day pass
    int a = costs[0] + slove(i + 1, days, costs, dp);

    // Cost for a 7-day pass
    int maxday = days[i] + 7;
    int j = i;
    while (j < days.size() && days[j] < maxday)
        j++;
    int b = costs[1] + slove(j, days, costs, dp);

    // Cost for a 30-day pass
    int maxday1 = days[i] + 30;
    int j1 = i;
    while (j1 < days.size() && days[j1] < maxday1)
        j1++;
    int c = costs[2] + slove(j1, days, costs, dp);

    // Store and return the minimum cost
    return dp[i] = min({a, b, c});
}


    int mincostTickets(vector<int>& days, vector<int>& costs) {
      vector<int>dp(366,-1);
        return slove(0, days, costs,dp);
    }
};