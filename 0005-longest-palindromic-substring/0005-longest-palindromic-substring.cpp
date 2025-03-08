/*

    Time Complexity : O(N^3), Here three nested loop creates the time complexity. Where N is the size of the
    string(s).

    Space Complexity : O(1), Constant space.

    Solved using string(Three Nested Loop). Brute Force Approach.

    Note : this may give TLE.

*/


/***************************************** Approach 1 *****************************************/

class Solution {
private: 
   vector<vector<int>> t; // Dynamic DP table

    bool check(string &s, int i, int j) {
        if (i >= j) return 1;
        if (t[i][j] != -1) return t[i][j];

        if (s[i] == s[j]) 
            return t[i][j] = check(s, i + 1, j - 1); 

        return t[i][j] = 0;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        t.assign(n, vector<int>(n, -1));

        int starting_index = 0;
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (check(s, i, j)) {
                    if (j - i + 1 > max_len) {
                        max_len = j - i + 1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 
