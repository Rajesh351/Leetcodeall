#include <stack>
#include <string>
#include <vector>
#include <map>

class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        std::stack<std::pair<std::string, int>> st;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (isupper(formula[i])) {
                std::string element;
                element += formula[i];
                i++;
                while (i < n && islower(formula[i])) {
                    element += formula[i];
                    i++;
                }
                std::string countStr;
                while (i < n && isdigit(formula[i])) {
                    countStr += formula[i];
                    i++;
                }
                int count = (countStr.empty()) ? 1 : std::stoi(countStr);
                st.push({element, count});
            } else if (formula[i] == '(') {
                st.push({"(", -1});
                i++;
            } else if (formula[i] == ')') {
                std::vector<std::pair<std::string, int>> temp;
                i++;
                std::string countStr;
                while (i < n && isdigit(formula[i])) {
                    countStr += formula[i];
                    i++;
                }
                int count = (countStr.empty()) ? 1 : std::stoi(countStr);

                while (!st.empty() && st.top().first != "(") {
                    auto element = st.top();
                    st.pop();
                    temp.push_back({element.first, element.second * count});
                }
                if (!st.empty() && st.top().first == "(") {
                    st.pop(); // Remove the '(' marker
                }

                // Push all elements back to the stack
                for (auto& p : temp) {
                    st.push(p);
                }
            }
        }

        std::map<std::string, int> atomCounts;
        while (!st.empty()) {
            auto element = st.top();
            st.pop();
            atomCounts[element.first] += element.second;
        }

        std::string result;
        for (auto& p : atomCounts) {
            result += p.first;
            if (p.second > 1) {
                result += std::to_string(p.second);
            }
        }

        return result;
    }
};
