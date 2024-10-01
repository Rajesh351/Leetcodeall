class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderFreq;

        // Step 1: Calculate remainder frequencies
        for (int num : arr) {
            int remainder = ((num % k) + k) % k;  // This ensures the remainder is positive
            remainderFreq[remainder]++;
        }

        // Step 2: Check if valid pairs can be formed
        for (auto& entry : remainderFreq) {
            int remainder = entry.first;
            int freq = entry.second;

            if (remainder == 0) {
                // Numbers divisible by k must pair with themselves
                if (freq % 2 != 0) return false;
            } else {
                // The number of elements with remainder `r` must equal the number of elements with remainder `k - r`
                int complement = k - remainder;
                if (remainderFreq[remainder] != remainderFreq[complement]) return false;
            }
        }

        return true;
    }
};
