class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int ans = INT_MIN, total = 0;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
            total += it;
        } 
        for(auto it: nums){
            int currSum = total-it;
            mp[it]--;
            if(mp[it] == 0) mp.erase(it);
            if(currSum%2 == 0 && mp.find(currSum/2) != mp.end() && it > ans){
                ans = it;
            }
            mp[it]++;
        }
        return ans;
    }
};