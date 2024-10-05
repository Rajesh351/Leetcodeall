class Solution {
public:

vector<int> findAnagrams(string s, string p) {
   vector<int> ans;
    if (p.size() > s.size()) return {};

    unordered_map<char, int> mp1, mp2;

    // Fill the map with characters from the pattern string
    for (char c : p) {
        mp1[c]++;
    }

    int pLen = p.size(), sLen = s.size();

    // Initialize the first window
    for (int i = 0; i < pLen; i++) {
        mp2[s[i]]++;
    }

    // Sliding window over the string `s`
    for (int i = 0; i <= sLen - pLen; i++) {
        // Check if the current window is an anagram
        if (mp1 == mp2) {
            ans.push_back(i);
        }

        // Slide the window: Remove the character at `i` and add the character at `i + pLen`
        mp2[s[i]]--;  // Remove the character at the start of the current window
        if (mp2[s[i]] == 0) {
            mp2.erase(s[i]);  // Remove the character from the map if its count is 0
        }

        if (i + pLen < sLen) {
            mp2[s[i + pLen]]++;  // Add the new character at the end of the window
        }
    }

    return ans;
}

};