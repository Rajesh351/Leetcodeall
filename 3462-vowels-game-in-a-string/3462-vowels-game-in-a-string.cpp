class Solution {
public:
    bool doesAliceWin(string s) {
        
     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int vowelCount = 0;
    for (char ch : s) {
        if (vowels.find(ch) != vowels.end()) {
            vowelCount++;
        }
    }
    return (vowelCount>0);
     
    }
};