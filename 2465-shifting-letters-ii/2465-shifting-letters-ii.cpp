class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
  int n = s.size();
        vector<int> shift(n + 1, 0); // Prefix sum array for net shifts

        // Accumulate the net shifts
        for (auto& shift_op : shifts) {
            int to = shift_op[0];
            int from = shift_op[1];
            int dir = shift_op[2];
            int value = (dir == 1) ? 1 : -1;

            shift[to] += value;
            shift[from + 1] -= value;
        }

        // Compute prefix sums to get the effective shift for each character
        int netShift = 0;
        for (int i = 0; i < n; i++) {
            netShift = (netShift + shift[i]) % 26;
            if (netShift < 0) netShift += 26; // Ensure netShift is non-negative

            // Apply the shift to the character
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
       
    }
};