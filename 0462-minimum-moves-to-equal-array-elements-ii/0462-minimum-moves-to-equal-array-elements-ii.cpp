class Solution {
public:
    int minMoves2(vector<int>& v) {
         int lo = 0;
        int hi = v.size() - 1;
        int mid = lo + ((hi - lo) / 2);
        sort(v.begin(), v.end());
        int j = mid + 1;
        int ans = 0;
        while (j < v.size()) {
            int rem = v[j] - v[mid];
            ans += rem ;
            j++;
        }
        int i = 0;
        while (i < mid) {
            int rem = v[mid] - v[i];
            ans += rem;
            i++;
        }
        return ans;
    }
};