class Solution {
public:
   bool checkIfExist(vector<int>& arr) 
{
     unordered_map<int,int>mp;
     for(int a:arr) mp[a]++;
     for(int a:arr)
     {
        if(mp.find(a*2)!=mp.end()) return true;
     }
     return false;
}
};