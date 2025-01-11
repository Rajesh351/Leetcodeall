class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) {
        return false;
    }

    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }

    // Count the number of characters with odd frequencies
    int oddCount = 0;
    for (const auto& entry : freq) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    // If the number of odd characters is greater than k, it's impossible to form k palindromes
    if (oddCount > k) {
        return false;
    }

    // Otherwise, it's possible to form exactly k palindromes
    return true;

    }
};