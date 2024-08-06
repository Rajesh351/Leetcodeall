class Solution {
public:
    int minimumPushes(string word) {
        std::map<char, int> charFrequency;

    for (char ch :word) {
        charFrequency[ch]++;
    }
    vector<int>v;
    for (auto rit = charFrequency.rbegin(); rit != charFrequency.rend(); ++rit) {
       v.push_back(rit->second);
    }
    sort(v.begin(),v.end(),greater());
    int sum=0;
    int press=1;
    int count=1;
    for(int i=0;i<v.size();i++)
    {
        if(count==9)
        {
            press++;
            count=1;
        }
        sum+=press*v[i];
        count++;
    }
    return sum;

    }
};