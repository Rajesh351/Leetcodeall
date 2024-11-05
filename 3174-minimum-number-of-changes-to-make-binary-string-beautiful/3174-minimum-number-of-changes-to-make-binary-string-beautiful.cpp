class Solution {
public:
    int minChanges(string s) {
      
      int i=0;
      int count=0;
      while(i<s.size())
      {

         char s2=s[i];
         i+=1;
         char s1=s[i];
         i+=1;
         if(s1!=s2) count++;
      }
      return count;
    }
};