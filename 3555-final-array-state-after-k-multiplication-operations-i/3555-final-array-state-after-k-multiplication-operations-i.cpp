class Solution {
public:
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Compare by value first
        if (a.first == b.first) {
            // If values are equal, compare by index
            return a.second > b.second; // Prioritize smaller index
        }
        return a.first > b.first; // Prioritize smaller value
    }
};
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
       priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
       for(int i=0;i<nums.size();i++)
       {
        minHeap.push({nums[i],i});
       }
       while(k>0)
       {
          auto it=minHeap.top();
          minHeap.pop();
          minHeap.push({it.first*multiplier,it.second});
          k--;
       }
       vector<int>v(nums.size(),0);
       while(!minHeap.empty())
       {
          auto it=minHeap.top();
          minHeap.pop();
          v[it.second]=it.first;
          
       }
       //reverse(v.begin(),v.end());
       return v;
    }
};