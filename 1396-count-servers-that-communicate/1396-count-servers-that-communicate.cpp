class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

       vector<int> row(grid.size(), 0);
vector<int> col(grid[0].size(), 0);

for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
            row[i]++;
            col[j]++;
        }
    }
}

int ans = 0;

for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
            // Check if the server is non-isolated
            if (row[i] > 1 || col[j] > 1) {
                ans++;
            }
        }
    }
}

return ans;

    }
};