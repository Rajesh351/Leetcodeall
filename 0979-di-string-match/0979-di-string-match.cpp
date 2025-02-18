class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        int j=0;
        vector<int>v;
        int a=0;
        int d=0;
        int i=0;
        while(i<s.size())
        {
             if(s[i]=='D') 
             {
                v.push_back(n--);
                d++;
             }
             else
             {
                 v.push_back(j++);
                 a++;
             }
             i++;
        }
        if(d==0) v.push_back(j);
        else if(a==0) v.push_back(n);
        else if(d>a) v.push_back(j);
        else  v.push_back(n);
        return v;
    }
};