class Solution {
public:
       vector<vector<int>> ans;
    unordered_set<string> uniquePerms; // To store unique permutations as strings

    void solve(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            // Convert nums to a string to check uniqueness
            string key = "";
            for (int num : nums) key += to_string(num) + ",";
            if (uniquePerms.find(key) == uniquePerms.end()) {
                uniquePerms.insert(key);
                ans.push_back(nums);
            }
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);    // Swap to generate a new permutation
            solve(idx + 1, nums);       // Recurse for the next index
            swap(nums[idx], nums[i]);   // Backtrack to restore the original order
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
           solve(0,nums);
         return ans;
    }
};