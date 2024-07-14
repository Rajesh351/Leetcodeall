class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        // Sort cuts in descending order
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        
        int i = 0, j = 0;
        int hcuts = 1, vcuts = 1;
        long long ans = 0;

        // Process the cuts using a greedy approach
        while (i < horizontalCut.size() || j < verticalCut.size()) {
            if (i < horizontalCut.size() && (j >= verticalCut.size() || horizontalCut[i] >= verticalCut[j])) {
                ans += horizontalCut[i] * vcuts;
                hcuts++;
                i++;
            } else {
                ans += verticalCut[j] * hcuts;
                vcuts++;
                j++;
            }
        }
        
        return ans;
    }
};