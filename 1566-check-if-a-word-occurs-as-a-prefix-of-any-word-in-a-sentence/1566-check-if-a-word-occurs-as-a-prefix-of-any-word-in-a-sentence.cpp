class Solution {
public:
    int isPrefixOfWord(string str, string w) {

        stringstream s(str);

        // To store individual words
        string word;
        unordered_map<char, int> mp;
        for (char a : w)
            mp[a]++;
        int m = w.size();
        int count = 0;
        while (s >> word)
        {
            int j = 0;
            count++;
            if(word==w) return count;
            int i=0;
            while(i<word.size() && j<w.size() && word[i]==w[j])
            {
                    i++;
                    j++;
            }
        
        if (m == j)
            return count;
        }
        return -1;
    }
    
};