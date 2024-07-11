class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int>st;
        int sum=0;
        int i=0;
        int curr=0;
        for(char a:s)
        {
           if(a=='(') 
           {
            st.push(curr);
            curr=0;
           }
           else
           {
            curr+=st.top()+max(curr,1);
            st.pop();
           }
        }
        return curr;
       
    }
};