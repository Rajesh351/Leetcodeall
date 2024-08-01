class Solution {
public:
    int numberOfSubstrings(string s) {
         int n = s.length();
    unordered_map<char, int> charCount;
    int left = 0, count = 0;

    for (int right = 0; right < n; right++) {
        charCount[s[right]]++;

        // Check if we have at least one 'a', 'b', and 'c'
        while (charCount['a'] > 0 && charCount['b'] > 0 && charCount['c'] > 0) {
            // All substrings from left to end of string are valid
            count += n - right;

            // Move left to try to find a new window
            charCount[s[left]]--;
            left++;
        }
    }

    return count;
    }
};