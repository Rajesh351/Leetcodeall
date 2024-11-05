class Solution {
public:
    int minChanges(string s) {
      char ch=s[0];
      int change=0,count=0;
      for(int i=0;i<s.size();i++)
      {
        if(ch==s[i])
        {
            count++;
            continue;
        }
        if(count%2==0)
        {
            count=1;
        }
        else
        {
             change+=1;
             count=0;
        }
        ch=s[i];
      }  
      return change;
    }
};