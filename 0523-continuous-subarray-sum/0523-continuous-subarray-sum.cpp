class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
  unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            sum %= k;
            if(mp.find(sum) != mp.end()){
                if(i - mp[sum] > 1) return true;
            }else{
                mp[sum] = i;
            }
        }
        return false;
    }
};