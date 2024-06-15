class Solution {
public:
#define ll long long 
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vp;
        priority_queue<int,vector<int>,greater<int>>pq;
          ll ans=0,sum=0;
        for(int i=0;i<nums1.size();i++){
             vp.push_back({nums2[i],nums1[i]});
        }
        sort(vp.begin(),vp.end(),greater<>());
         for(int j=0;j<nums1.size();j++){
              sum+=vp[j].second;
              pq.push(vp[j].second);
             if(pq.size()<k){
                  continue;
             }
            if(pq.size()==k){
               ans=max(ans,sum*vp[j].first);
               sum-=pq.top();
               pq.pop();
            }
         }
         return ans;
    }
};