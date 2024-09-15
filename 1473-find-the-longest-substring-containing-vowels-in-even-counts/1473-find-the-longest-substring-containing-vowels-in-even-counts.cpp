class Solution {
public:
    int findTheLongestSubstring(string s) {

         unordered_map<int, int> first_occurrence;
    
    // Initialize with the base case where all vowels have appeared 0 times (even)
    first_occurrence[0] = -1;
    
    int bitmask = 0;
    int ans = 0;
    
    // Mapping vowels to respective bits
    unordered_map<char, int> vowel_mask = {{'a', 1 << 0}, {'e', 1 << 1}, {'i', 1 << 2}, {'o', 1 << 3}, {'u', 1 << 4}};
    
    for (int i = 0; i < s.size(); i++) {
        // Toggle the bit corresponding to the current vowel
        if (vowel_mask.find(s[i]) != vowel_mask.end()) {
            bitmask ^= vowel_mask[s[i]];
        }
        
        // If this bitmask has been seen before, calculate the length of the valid substring
        if (first_occurrence.find(bitmask) != first_occurrence.end()) {
            ans = max(ans, i - first_occurrence[bitmask]);
        } else {
            // Store the first occurrence of this bitmask
            first_occurrence[bitmask] = i;
        }
    }
    
    return ans;
    }
};