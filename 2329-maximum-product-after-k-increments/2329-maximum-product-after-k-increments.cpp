class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        
    priority_queue <int, vector<int>, greater<int> >pq; 
    for(int a:nums) pq.push(a);
    while(k!=0)
    {
        int a=pq.top();
        pq.pop();
        pq.push(a+1);
        k--;
    }
      
     long long sum=1;
     int mod=1000000007;
     while(!pq.empty())
     {
        sum=sum%mod;
        sum=(sum*pq.top())%mod;
        pq.pop();
     }
     return int(sum);
    }
};