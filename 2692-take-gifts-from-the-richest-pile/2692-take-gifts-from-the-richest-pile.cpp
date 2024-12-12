class Solution {
public:
    
    long long pickGifts(vector<int>& gifts, int k) {
        
      priority_queue<int>hp;
      for(int a:gifts) hp.push(a);
      while(k--)
      {
         int ele=hp.top();
          hp.pop();
         hp.push(sqrt(ele));
      }
      long long ans=0;
      while(!hp.empty())
      {
         ans+=hp.top();
         hp.pop();
      }
      return ans;
    }
};