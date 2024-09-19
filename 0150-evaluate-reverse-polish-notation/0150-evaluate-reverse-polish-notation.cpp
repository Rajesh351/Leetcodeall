class Solution {
public:
    int evalRPN(vector<string>& str) {


        stack<int>st;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=="+"|| str[i]=="-"|| str[i]=="/"||str[i]=="*")
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(str[i]=="+") st.push(num1+num2);
                else if(str[i]=="-") st.push(num1-num2);
                else if(str[i]=="*") st.push(num1*num2);
                else if(str[i]=="/" && num2!=0) st.push(num1/num2);
            }
            else
            {
               int num=stoi(str[i]); 
               st.push(num);
            }
        }  
        return st.top();
    }
};