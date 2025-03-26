class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> v;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                v.push_back(grid[i][j]);
            }
        }
        int lo = 0;
        int hi = v.size() - 1;
        int mid = lo + ((hi - lo) / 2);
        sort(v.begin(), v.end());
        int j = mid + 1;
        int ans = 0;
        while (j < v.size()) {
            int rem = v[j] - v[mid];
            if (rem % x != 0)
                return -1;
            ans += rem / x;
            j++;
        }
        int i = 0;
        while (i < mid) {
            int rem = v[mid] - v[i];
            if (rem % x != 0)
                return -1;
            ans += rem / x;
            i++;
        }
        return ans;
    }
};