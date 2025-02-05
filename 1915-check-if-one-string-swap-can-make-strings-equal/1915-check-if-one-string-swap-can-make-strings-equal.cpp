class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
    
      if(s1.size()==1)
      {
        if(s1[0]!=s2[0]) return false;
        return true;
      }
      
      int count=0;
      for(int i=0;i<s2.size();i++)
      {
        if(s1[i]!=s2[i]) count++;
      }
      if(count>2) return false;
      vector<int>v(26,0);
      vector<int>v1(26,0);
      for(int i=0;i<s1.size();i++)
      {
         v[s1[i]-'a']++;
          v1[s2[i]-'a']++;
      }
      for(int i=0;i<26;i++)
      {
        if(v[i]!=v1[i]) return false;
      }
      return true;
    
    }
};