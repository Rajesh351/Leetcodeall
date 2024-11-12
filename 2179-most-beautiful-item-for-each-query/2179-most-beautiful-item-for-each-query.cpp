class Solution {
    int bs(vector<vector<int>>& items, int t, vector<int> &beauty) {
        int ans = 0, s = 0, e = items.size() - 1;
        while(s <= e) {
            int m = (s + e) / 2;
            if(items[m][0] <= t) ans = beauty[m], s = m + 1;
            else e = m - 1;
        }
        return ans;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<int> ans, beauty(items.size(), items[0][1]);

        for(int i=1; i<items.size(); i++) beauty[i] = max(beauty[i - 1], items[i][1]);

        for(int i : queries) ans.push_back(bs(items, i, beauty));
        return ans;
    }
};