class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<int,char>>st;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') st.push({str.size(),'('});
            else if(s[i]==')')
            {
                 int start=st.top().first;
                 int end=str.size();
                 st.pop();
                 reverse(str.begin() + start, str.begin() + end );
            }
            else str+=s[i];
        }
        return str;
    }
};