class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        // Ensure that s1 is the longer sentence
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        // Split both sentences into words
        vector<string> str1, str2;
        stringstream ss(s1);
        string word;
        while (ss >> word) {
            str1.push_back(word);
        }
        
        stringstream ss1(s2);
        string word1;
        while (ss1 >> word1) {
            str2.push_back(word1);
        }
        
        // Check similarity from the beginning of both sentences
        int i = 0;
        int j = 0;
        while (i < str1.size() && j < str2.size() && str1[i] == str2[j]) {
            i++;
            j++;
        }
        
        // Check similarity from the end of both sentences
        int k = str1.size() - 1;
        int l = str2.size() - 1;
        while (l >= j && str1[k] == str2[l]) {
            k--;
            l--;
        }
        
        // If all the words of str2 have been matched, return true
        return l < j;
    }
};
