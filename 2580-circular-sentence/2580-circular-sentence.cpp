class Solution {
public:
    bool isCircularSentence(string str) {

    
    std::stringstream s(str);
    std::string word;
    std::vector<std::string> v;

    while (s >> word) {
        v.push_back(word);
        if (v.size() > 1) {
            std::string a = v[v.size() - 2];
            std::string b = v[v.size() - 1];
            if (a[a.size() - 1] != b[0]) return false;
        }
    }
    if (v.size() > 1) {
        std::string a = v[0];
        std::string b = v[v.size() - 1];
        if (b[b.size() - 1] != a[0]) return false;
    }
    else
    {
        if(str[0]!=str[str.size()-1]) return false;
    }
    
    return true;
    }
};