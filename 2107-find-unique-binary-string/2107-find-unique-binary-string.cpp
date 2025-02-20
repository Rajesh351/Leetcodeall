class Solution {
public:
    unordered_set<string> mp; // Use unordered_set for faster lookups
    string ans = "";

    void solve(string str, int n) {
        if (str.size() == n) { // Base condition: when string reaches size n
            if (mp.find(str) == mp.end()) { // If not in the given set
                ans = str;
            }
            return;
        }
        if (!ans.empty()) return; // Stop if we found the answer

        str.push_back('0');
        solve(str, n);
        str.pop_back();

        if (!ans.empty()) return; // Stop unnecessary recursion

        str.push_back('1');
        solve(str, n);
        str.pop_back();
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        
        for (const string& str : nums) {
            mp.insert(str); // Store all given binary strings
        }

        string str = "";
        solve(str, n);
        return ans;
    }
};
