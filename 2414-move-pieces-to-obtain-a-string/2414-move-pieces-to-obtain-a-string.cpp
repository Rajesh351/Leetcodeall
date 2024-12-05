class Solution {
public:
    bool canChange(string start, string target) {

   if (start.size() != target.size()) return false;

        // Remove all underscores to check if the order of R and L matches
        string s1, s2;
        for (char c : start) {
            if (c != '_') s1 += c;
        }
        for (char c : target) {
            if (c != '_') s2 += c;
        }
        if (s1 != s2) return false;

        // Check for relative positions of R and L
        int tIndex = 0, sIndex = 0;
        while (tIndex < target.size() && sIndex < start.size()) {
            // Skip underscores in both strings
            while (sIndex < start.size() && start[sIndex] == '_') sIndex++;
            while (tIndex < target.size() && target[tIndex] == '_') tIndex++;

            if (sIndex < start.size() && tIndex < target.size()) {
                // R can only move right and L can only move left
                if ((start[sIndex] == 'R' && sIndex > tIndex) ||
                    (start[sIndex] == 'L' && sIndex < tIndex)) {
                    return false;
                }
                sIndex++;
                tIndex++;
            }
        }

        return true;
        
    }
};