class Solution {
public:
    int numberOfSubstrings(string s) {

        unordered_map<int, int> mp;
        int i = 0, j = 0, count = 0;

        while (j < s.size()) {
            mp[s[j] - '0']++; // Character count बढ़ाएं

            while (mp.size() > 2) {    // केवल 2 distinct characters तक सीमित रखें
                count += s.size() - j; // सभी valid substrings add करें
                if (--mp[s[i] - '0'] == 0) {
                    mp.erase(s[i] - '0');
                }
                i++;
            }

            j++;
        }

        return count;
    }
};