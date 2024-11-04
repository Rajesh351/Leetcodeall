class Solution {
public:
    int compress(vector<char>& chars) {
       vector<char> v;
    int count = 1;
    int i = 0;

    for (i = 0; i < chars.size() - 1; i++) {
        if (chars[i] == chars[i + 1]) {
            count++;
        } else {
            v.push_back(chars[i]);
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    v.push_back(c);
                }
            }
            count = 1;  // Reset count for the next character sequence
        }
    }

    // Handle the last character sequence
    v.push_back(chars[i]);
    if (count > 1) {
        string countStr = to_string(count);
        for (char c : countStr) {
            v.push_back(c);
        }
    }

    chars = v; // Replace original vector with compressed version
    return v.size();

    }
};