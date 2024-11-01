class Solution {
public:
    string makeFancyString(string s) {
       std::string result;
    for (char c : s) {
        int n = result.size();
        
        // చివరి రెండు అక్షరాలు అదే కాబట్టి, ప్రస్తుతం వచ్చిన అక్షరం కూడా అలాగే ఉంటే, వెనుక అక్షరాన్ని తొలగించాలి
        if (n >= 2 && result[n - 1] == c && result[n - 2] == c) {
            continue;
        }
        
        // అదే అక్షరాలు వరుసగా వస్తే, ఒక్క character ని చేర్చడం ద్వారా మాత్రమే పనిచేస్తుంది
        result.push_back(c);

    }
     return result;
    }
};