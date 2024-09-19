class Solution {
public:

vector<int> solve(string str) {
    vector<int> res;
    // Iterate through the string
    for (int i = 0; i < str.size(); i++) {
        // Check if the current character is an operator
        if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
            // Recursively solve the left and right parts of the expression
            vector<int> left = solve(str.substr(0, i));
            vector<int> right = solve(str.substr(i + 1));
            
            // Combine the results from the left and right parts based on the operator
            for (auto a : left) {
                for (auto b : right) {
                    if (str[i] == '+') res.push_back(a + b);
                    else if (str[i] == '-') res.push_back(a - b);
                    else if (str[i] == '*') res.push_back(a * b);
                }
            }
        }
    }

    // If the string is a number, push it into the result vector
    if (res.empty()) {
        res.push_back(stoi(str));
    }
    return res;
}

vector<int> diffWaysToCompute(string str) {
    return solve(str);
}

};