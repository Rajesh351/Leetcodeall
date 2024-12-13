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
         while (mp.size() < nums.size()) {
        if (minHeap.empty()) break;

        auto it = minHeap.top();
        minHeap.pop();

        int value = it.first;
        int index = it.second;

        // Skip if the current index is already marked
        if (mp.find(index) != mp.end()) {
            continue;
        }

        // Add the value to the score
        score += value;

        // Mark the current index and adjacent indices
        mp[index]++;
        if (index - 1 >= 0) mp[index - 1]++;
        if (index + 1 < nums.size()) mp[index + 1]++;
    }
        return score;  

    }
};