class Solution {
public:
    string removeOccurrences(string s, string part) {

        while (!s.empty()) {
            size_t found = s.find(part);
            if (found != string::npos) {
                int idx = s.find(part);
                s.erase(idx,part.size());
            } else {
                return s;
            }
        }
        return s;
    }
};