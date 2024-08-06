class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0)
            return {};

        std::unordered_map<int, std::string> keys = {
            {2, "abc"}, {3, "def"},  {4, "ghi"}, {5, "jkl"},
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

        std::vector<std::string> v, v1;
        int a = digits[0] - '0';
        std::string str = keys.at(a);
        for (int i = 0; i < str.size(); i++) {
            std::string c(1, str[i]);
            v.push_back(c);
        }

        for (int i = 1; i < digits.size(); i++) {
            int a = digits[i] - '0';
            std::string str = keys.at(a);
            v1.clear(); 

            for (int j = 0; j < v.size(); j++) {
                for (int k = 0; k < str.size(); k++) {
                    std::string s = v[j] + str[k]; 
                    v1.push_back(s);
                }
            }

            v = v1;
        }

        return v;
    }
};