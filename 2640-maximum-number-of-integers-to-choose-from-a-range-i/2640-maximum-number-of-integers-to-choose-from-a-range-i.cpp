class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int>mp;
        for(auto a:banned) mp[a]++;
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                v.push_back(i);
            }
        }
        if(v.size()==0) return 0;
        int sum=0;
        int i=0;
         for(i=0;i<v.size();i++)
         {
              sum+=v[i];
              if(sum>maxSum) return i;
         }
         if(maxSum>sum) return i;
         return 0;
    }
};