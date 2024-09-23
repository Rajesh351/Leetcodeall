class Solution {
public:
    int solve(int i, string s, set<string>& st, vector<int>& v) {
        // Base case: if we have processed the entire string
        if (i >= s.size())
            return 0;

        // If the result is already calculated, return it
        if (v[i] != -1)
            return v[i];

        string rem = "";
        int countextra = s.size();

        // Iterate through the string from index i to find substrings
        for (int j = i; j < s.size(); j++) {
            rem.push_back(s[j]);

            int count = 0;
            // If the substring is not in the dictionary, count it as extra
            // characters
            if (st.find(rem) == st.end()) {
                count = rem.size();
            }

            // Recursively find the next extra characters count from the next
            // position
            int nextextra = solve(j + 1, s, st, v);
            int total = nextextra + count;

            // Minimize the total extra characters
            countextra = min(countextra, total);
        }

        // Store and return the result for the current index
        return v[i] = countextra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // Initialize the memoization vector with -1
        vector<int> v(s.size(), -1);

        // Insert dictionary words into a set for quick lookup
        set<string> st(dictionary.begin(), dictionary.end());

        // Call the recursive solve function starting from index 0
        return solve(0, s, st, v);
    }
};