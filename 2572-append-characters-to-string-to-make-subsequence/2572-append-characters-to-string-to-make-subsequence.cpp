class Solution {
public:
    int appendCharacters(string s, string t) {
       int i=s.size();
       int j=t.size();
       int a=0,b=0;
       while(a<i && b<j)
       {
          if(s[a]==t[b])
          {
            a++;
            b++;
          }
          else a++;
       }
       return j-b;
    }
};