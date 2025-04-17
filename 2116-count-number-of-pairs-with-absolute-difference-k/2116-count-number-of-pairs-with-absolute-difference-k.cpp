class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
    int count = 0;

    for (int a : nums) {
        // Check for existing elements with the required differences
        if (mp.find(a - k) != mp.end()) count += mp[a - k];
        if (mp.find(a + k) != mp.end()) count += mp[a + k];
        
        // Increment the frequency of the current element
        mp[a]++;
    }

    return count;
    }
};