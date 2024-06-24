class Solution {
public:
    bool isprime(int n) {
        if (n == 1)
            return false;
        for (int j = 2; j <= sqrt(n); j++) {
            if (n % j == 0)
                return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {

        vector<int> v;
        int a = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back(nums[i][a--]);
            for (int j = 0; j < nums[0].size(); j++) {
                if (i == j)
                    v.push_back(nums[i][j]);
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            if (isprime(v[i])) {
                ans = max(ans, v[i]);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};