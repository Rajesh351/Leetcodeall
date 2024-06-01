class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++)
        {
           char a=s[i-1];
           char b=s[i];
            int a1=int(a);
            int b1=int(b);
            ans+=abs(a1-b1);
        }
        return ans;
        
    }
};