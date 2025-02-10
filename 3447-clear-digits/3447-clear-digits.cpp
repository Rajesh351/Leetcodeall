class Solution {
public:
    string clearDigits(string s) {

     string str;
      for(char c:s)
      {
         int a=c-'0';
         if(a>=0 && a<10)
         {
            if(str.size()!=0) str.erase(str.size()-1,1);
         }
         else str+=c;
      }
      return str;
    }
};