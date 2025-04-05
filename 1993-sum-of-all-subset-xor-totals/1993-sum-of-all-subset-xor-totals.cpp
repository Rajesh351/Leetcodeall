class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        
        vector<vector<int>> subsets = {{}};

    for (int i = 0; i < nums.size(); i++) {
        int currentSize = subsets.size();

        // For each existing subset, add the current element to create a new subset
        for (int j = 0; j < currentSize; j++) {
            vector<int> newSubset = subsets[j];
            newSubset.push_back(nums[i]);
            subsets.push_back(newSubset);
        }
    }

    // Print all subsets
    int sum=0;
    for (auto subset : subsets) {
        int curr=0;
        for (int val : subset) {
           curr=curr^val;
        }
       sum+=curr;
    }
    return sum;
    }
};