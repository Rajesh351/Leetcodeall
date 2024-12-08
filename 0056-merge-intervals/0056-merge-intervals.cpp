class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        // Sort the intervals based on the start value
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);  // Push the first interval
        
        for (int i = 1; i < arr.size(); i++) {
            // If the current interval overlaps with the last one in 'ans'
            if (ans.back()[1] >= arr[i][0]) {
                // Merge the intervals by updating the end of the last interval
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            } else {
                // No overlap, just add the current interval to 'ans'
                ans.push_back(arr[i]);
            }
        }
        
        return ans;
    }
};
