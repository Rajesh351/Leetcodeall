class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        
        unordered_map<int,int>mp;
        for(auto a:banned) mp[a]++;
         int sum=0;
        int i=0;
        int count=0;
        for(i=1;i<=n;i++)
        {
            
            if(mp.find(i)==mp.end())
            {
                 sum+=i;
                 count++;
              if(sum>maxSum) return count-1;
            }
        }
         if(maxSum>sum) return count;
         return 0;
    }
};