class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
       

         int n = nums.size();
        vector<int> prefixMax = nums;
        vector<int> suffixMax = nums;
        for(int i = 1; i < n; i++)
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1]);
        for(int i = n-2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
        }
        long long res = 0;
        for(int j = 1; j < n-1; j++) {
            long long vali = prefixMax[j-1];
            long long valj = nums[j];
            long long valk = suffixMax[j+1];
            long long curr = (vali - valj) * valk;
            res = max(res, curr);
        }
        return res;
    }
};