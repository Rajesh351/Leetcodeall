class Solution {
public:
bool solve(string &s, unordered_map<string, int> &mp, int i, unordered_map<int, bool> &dp) {
    if (i == s.size()) return true; 

    if (dp.find(i) != dp.end()) return dp[i];  

    string str = "";
    for (int j = i; j < s.size(); j++) {  
        str += s[j];  // Form substring

        if (mp.find(str) != mp.end()) {  
            if (solve(s, mp, j + 1, dp)) {  
                return dp[i] = true;
            }
        }
    }

    return dp[i] = false;  // No valid segmentation found
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, int> mp;
    unordered_map<int, bool> dp;  // Memoization map

    for (string word : wordDict) {
        mp[word]++;  // Store words in dictionary
    }

    return solve(s, mp, 0, dp);
}
};