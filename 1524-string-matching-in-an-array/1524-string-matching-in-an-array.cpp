class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
         for (int i = 0; i < words.size(); i++) {
           string text = words[i];
        if (text.empty()) continue; // Skip empty strings

        for (int j = i + 1; j < words.size(); j++) {
            if (words[j].empty()) continue; // Skip empty strings

            if (text.find(words[j]) != string::npos) {
                ans.push_back(words[j]); // `words[j]` is a substring of `text`
                words[j] = "";          // Mark as processed
            } else if (words[j].find(text) != string::npos) {
                ans.push_back(text);    // `text` is a substring of `words[j]`
                break;                  // No need to check further for `text`
            }
        }
    }
    return ans;
    }
};