class Solution {
public:
   int solve(int i, int j, vector<int>& arr, unordered_map<int, int>& mp) {
        int tar = arr[j] - arr[i];
        if (mp.count(tar) && mp[tar] < i) {
            int k = mp[tar];
            return solve(k, i, arr, mp) + 1;
        }
        return 2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) 
            mp[arr[i]] = i;

        int res = 0;
        for (int i = 1; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int len = solve(i, j, arr, mp);
                res = max(res, len);
            }
        }
        return res > 2 ? res : 0;
    }
};