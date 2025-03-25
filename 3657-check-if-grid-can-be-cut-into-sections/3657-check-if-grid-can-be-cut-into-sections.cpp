class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<pair<int, int>> X, Y;

        for (int i = 0; i < rectangles.size(); i++) {
            X.push_back({rectangles[i][0], rectangles[i][2]});
            Y.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        vector<pair<int, int>> ans, ans1;
        ans.push_back(X[0]);

        for (int i = 1; i < X.size(); i++) {
            if (X[i].first < ans.back().second) {
                ans.back().second = max(ans.back().second, X[i].second);
            } else {
                ans.push_back(X[i]);
            }
        }

        ans1.push_back(Y[0]);
        for (int i = 1; i < Y.size(); i++) {
            if (Y[i].first < ans1.back().second) {
                ans1.back().second = max(ans1.back().second, Y[i].second);
            } else {
                ans1.push_back(Y[i]);
            }
        }
        return ans.size()>=3 || ans1.size()>=3;
    }
};