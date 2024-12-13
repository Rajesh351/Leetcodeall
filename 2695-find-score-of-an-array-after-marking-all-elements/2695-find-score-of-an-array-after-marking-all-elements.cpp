class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        unordered_map<int,int>mp;
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
          for(int i=0;i<nums.size();i++)
          {
              minHeap.push({nums[i],i});
          }
          
           long long score=0;

          while(mp.size()<nums.size())
          {
             if(minHeap.empty()) break;
          auto it=minHeap.top();
          minHeap.pop();
          if(mp.find(it.second)!=mp.end()) continue;
          
            score+=it.first;
          
           mp[it.second]++;
          if(it.second-1>=0)mp[it.second-1]++;
          if(it.second+1<=nums.size()-1)  mp[it.second+1]++;
          }
          return score;

    }
};