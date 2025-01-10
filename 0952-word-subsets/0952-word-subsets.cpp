class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{

     vector<int> maxFreq(26, 0);

    for (const string &word : words2)
    {
        vector<int> freq(26, 0);
        for (char ch : word)
        {
            freq[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            maxFreq[i] = max(maxFreq[i], freq[i]);
        }
    }

    // Check which words in words1 satisfy the universal condition
    vector<string> ans;
    for (const string &word : words1)
    {
        vector<int> freq(26, 0);
        for (char ch : word)
        {
            freq[ch - 'a']++;
        }

        bool isUniversal = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] < maxFreq[i])
            {
                isUniversal = false;
                break;
            }
        }

        if (isUniversal)
        {
            ans.push_back(word);
        }
    }

    return ans;
}
};