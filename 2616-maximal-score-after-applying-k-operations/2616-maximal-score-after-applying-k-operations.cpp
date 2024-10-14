class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
       priority_queue<int> pq;
      for(auto a:nums) pq.push(a);
      long long ans=0;
       while(k--)
       {
          ans+=pq.top();
          int a=pq.top();
          pq.pop();
          pq.push(ceil(static_cast<double>(a) / 3));
       } 
       return ans;
    }
};