class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string, int> mp;
        std::stringstream ss(s1);
        std::string word;

        while (ss >> word) {

            mp[word]++;
        }
         stringstream ss2(s2);
         string word1;

        while (ss2 >> word1) {

            mp[word1]++;
        }
        vector<string> ans;
        for (auto it : mp) {
            if (it.second == 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};