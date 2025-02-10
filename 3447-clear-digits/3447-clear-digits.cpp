class Solution {
public:
    string clearDigits(string s) {

      stack<char>st;
      for(char c:s)
      {
         int a=c-'0';
         if(a>=0 && a<10)
         {
            if(!st.empty()) st.pop();
         }
         else st.push(c);
      }
      string str;
      while(!st.empty())
      {
        str+=st.top();
        st.pop();
      }
      reverse(str.begin(),str.end());
      return str;
    }
};