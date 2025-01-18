class Solution {
public:
    const int INF = 1e9;
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<tuple<int,int,int>> s;
        vector<vector<int>> dp(n, vector<int>(m, INF));
        dp[0][0] = 0;
        s.insert({0, 0, 0});
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!s.empty()) {
            auto [cost,row,col] = *s.begin();
            s.erase(*s.begin());
            if (cost > dp[row][col]) continue;
            for (int x = 0; x < 4; x++) {
                int nr = row + dx[x];
                int nc = col + dy[x];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                int newcost = cost + (x + 1 != grid[row][col]);
                if (newcost < dp[nr][nc]) {
                    dp[nr][nc] = newcost;
                    s.insert({newcost, nr, nc});
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
