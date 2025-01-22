class Solution {
public:
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> pq;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    pq.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();
            for (auto a : dir) {
                int i = it.first + a[0];
                int j = it.second + a[1];
                if (i >= 0 && i < m && j >= 0 && j < n && ans[i][j] == -1) {
                    ans[i][j] = ans[it.first][it.second] + 1;
                    pq.push({i, j});
                }
            }
        }
        return ans;
    }
};