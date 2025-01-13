class Solution {
public:
    int minimumLength(string s) {
        
      unordered_map<char,int>mp;
      for(char a:s)
      {
         mp[a]++;
         if(mp[a]==3)
         {
            mp[a]=1;
         }
      }
      int ans=0;
      for(auto it:mp)
      {
        ans+=it.second;
      }
      return ans;
    }
};