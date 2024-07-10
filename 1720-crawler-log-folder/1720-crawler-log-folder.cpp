class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string>st;
        string onemove="../";
        string same="./";

        for(auto a:logs)
        {
            if(onemove==a && st.size()==0) continue;
            else if(onemove==a) st.pop();
            else if(same!=a) st.push(a); 
        }
        return st.size()==0?0:st.size();
    }
};