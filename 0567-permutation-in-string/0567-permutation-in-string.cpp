class Solution {
public:
    bool checkInclusion(string p, string s ) {
  unordered_map<char, int> mp1, mp2;

    // Base case: If pattern length is greater than string length, it's impossible
    if (p.size() > s.size()) {
        return false;
    }

    // Count the frequency of characters in the pattern
    for (char c : p) {
        mp1[c]++;
    }

    int pLen = p.size(), sLen = s.size();

    // Initialize the first window in the string s
    for (int i = 0; i < pLen; i++) {
        mp2[s[i]]++;
    }

    // Slide the window across the string s
    for (int i = 0; i <= sLen - pLen; i++) {
        // Check if the current window is a permutation of the pattern
        if (mp1 == mp2) {
            return true;
        }

        // Slide the window: remove the character at the start of the current window
        mp2[s[i]]--;
        if (mp2[s[i]] == 0) {
            mp2.erase(s[i]);  // Remove the character if its count reaches 0
        }

        // Add the next character in the window
        if (i + pLen < sLen) {
            mp2[s[i + pLen]]++;
        }
    }

    return false;
    }
};