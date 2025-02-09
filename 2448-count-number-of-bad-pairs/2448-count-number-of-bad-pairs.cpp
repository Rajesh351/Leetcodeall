class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
         int n = nums.size();
    unordered_map<int, int> mp;

    // Count occurrences of (i - nums[i])
    for (int i = 0; i < n; i++) {
        mp[i - nums[i]]++;
    }

    long long ans = 0;

    for (auto it : mp) {
        int freq = it.second;
        if (freq > 1) {
            ans += (1LL* freq * (freq - 1)/2) ;
        }
    }

    return (1LL * n * (n - 1) / 2) - ans; 
    }
};