class Solution {
public:
    string decodeString(string s) {

        stack<char> st;
        string ans = "";

        for (char ch : s) {
            if (ch != ']') {
                st.push(ch);
            } else {
                string temp = "";
                while (!st.empty() && st.top() != '[') {
                    temp += st.top();
                    st.pop();
                }
                reverse(temp.begin(), temp.end());

                // Pop the '['
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                }

                // Extract the number (multiplier)
                int multiplier = 1;
                int result = 0;
                int base = 1;
                while (!st.empty() && isdigit(st.top())) {
                    result = (st.top() - '0') * base + result;
                    base *= 10;
                    st.pop();
                }

                // Repeat the string `result` times and push back to stack
                string repeatedString = "";
                for (int i = 0; i < result; ++i) {
                    repeatedString += temp;
                }
                for (char rc : repeatedString) {
                    st.push(rc);
                }
            }
        }

        // Collect the final result from the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};