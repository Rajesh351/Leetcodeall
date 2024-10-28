class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        
      std::sort(nums.begin(), nums.end());
    std::unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int sq_root = static_cast<int>(std::sqrt(nums[i]));

        // Check if the square root is a perfect square and exists in the map
        if (sq_root * sq_root == nums[i] && mp.find(sq_root) != mp.end()) {
            mp[nums[i]] = mp[sq_root] + 1;  // Update chain length
        } else {
            mp[nums[i]] = 1;  // Start a new chain
        }
    }

    int ans = -1;
    for (auto& a : mp) {
        ans = std::max(ans, a.second);
    }
    return ans==1?-1:ans;
    }
};