class Solution {
    int findIfPos(int ind, vector<int>& preSum, int cnt, int k, int n, vector<vector<int>>&dp) {
        if (cnt == 0) return 0;
        if (ind + k > n) return -1e9 - 9; 
        if (dp[ind][cnt]!=-1)return dp[ind][cnt];

        int take = preSum[ind + k] - preSum[ind] + findIfPos(ind + k, preSum, cnt - 1, k, n, dp);
        int notTake = findIfPos(ind + 1, preSum, cnt, k, n, dp);

        return dp[ind][cnt] = max(take, notTake);
    }
   
    void findIdx(int ind, vector<int>& preSum, int k, int cnt, int n, vector<int>& result, vector<vector<int>>&dp) {
        if (cnt == 0) return;
        if (ind + k > n) return;
        
        int take = preSum[ind + k] - preSum[ind] + findIfPos(ind + k, preSum, cnt - 1, k, n, dp);
        int notTake = findIfPos(ind + 1, preSum, cnt, k, n, dp);
        
        if (take >= notTake) {
            result.emplace_back(ind);
            findIdx(ind + k, preSum, k, cnt - 1, n, result, dp);
        } else {
            findIdx(ind + 1, preSum, k, cnt, n, result, dp);
        }
    }
    
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> result;
        int n = (int)nums.size();

        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        vector<vector<int>>dp(n,vector<int>(4,-1));        
        findIdx(0, preSum, k, 3, n, result,dp);
        return result;
    }
};