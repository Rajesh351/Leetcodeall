class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
       unordered_map<int,int>mp;
       for(int a:arr) mp[a]++;
       for(int a:target)
       {
          if(mp.find(a)!=mp.end() && mp[a] > 0) 
          {
            mp[a]--;
          }
          else  return false;
       }
       return true;
    }
};