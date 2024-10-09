class Solution {
public:
    int minAddToMakeValid(string s) {
        
       stack<char>st;
       for(char a:s)
       {
          if(a=='(') st.push(a);
          else if(a==')')
          {
             if(!st.empty() && st.top()=='(') st.pop();
             else st.push(a);
          }
         
       }
       return st.size();
    }
};