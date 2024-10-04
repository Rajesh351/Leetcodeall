class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

      sort(skill.begin(),skill.end());
     // unordered_map<int,int>mp;
      int i=0;
      int j=skill.size()-1;
      int count=skill[0]+skill[skill.size()-1];
      long long ans=0;
      int total=0;
      while(i<j)
      {
         if(skill[i]+skill[j]==count)
         {
            ans+=skill[i]*skill[j];
            total++;
         }  
         i++;
         j--;
      }
      int n=skill.size();
      if(n/2==total) return ans;
      return -1;
        
    }
};