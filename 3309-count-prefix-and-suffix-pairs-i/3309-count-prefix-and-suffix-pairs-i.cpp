class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {

        int count = 0;

    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            // Prefix चेक करें
            int a = 0;
            while (a < words[i].size() && a < words[j].size() && words[i][a] == words[j][a]) {
                a++;
            }

            // Suffix चेक करें
            int b = words[i].size() - 1;
            int c = words[j].size() - 1;
            while (b >= 0 && c >= 0 && words[i][b] == words[j][c]) {
                b--;
                c--;
            }
            if (b == -1 && a == words[i].size()) { // इसका मतलब `words[i]` `words[j]` का suffix है।
                count++;
            }
        }
    }

    return count;
    }
};