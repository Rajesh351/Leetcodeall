class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int a:nums) 
        {
             if(a%2==0) mp[a]++;
        }
        int ans=-1;
        int curr=0;
        for(auto it:mp)
        {
           if(curr<it.second)
           {
            curr=it.second;
            ans=it.first;
           }
           else 
           {
             if( curr==it.second) ans=min(ans,it.first);
           }
        }
        return ans;
    }
};