class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        
         int i=0;
         int j=j=0;
         while(i<str1.size() && j<str2.size())
         {
              if(str1[i]==str2[j])
              {
                i++;
                j++;
              }
              else if(str1[i]=='z' && str2[j]=='a') 
              {
                i++;
                j++;
              }
              else if(int(str1[i])+1==int(str2[j]))
              {
                i++;
                j++;
              }
              else i++;
         }
         if(j==str2.size()) return true;
         return false;
        
    }
};